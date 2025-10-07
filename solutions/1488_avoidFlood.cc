// Oct. 6th, 2025

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> lastRain;
        set<int> dryDays;

        for (int i=0; i<n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.insert(i);
                ans[i]=1;
                continue;
            }
            if (lastRain.count(lake)) {
                auto it = dryDays.upper_bound(lastRain[lake]);
                if (it == dryDays.end()) return {};
                ans[*it] = lake;
                dryDays.erase(it);
            }
            lastRain[lake] = i;
            ans[i] = -1;
        }
        return ans;
    }
};


// class Solution {
// private:
//     void PRINT(const vector<int>& vec) {
//         cout << "[";
//         for (const int& v : vec) cout << v << " ";
//         cout << "]" << endl;
//     }

// public:
//     vector<int> avoidFlood(vector<int>& rains) {
//         // reverse traverse with a stk
//         // and then pop the stk until you get something that is in the running hashset
//         stack<int> stk;
//         int n=rains.size();
//         for (int i=n-1; i>=0; --i)
//             if (rains[i] != 0) stk.push(rains[i]);

//         unordered_map<int,int> seen;
//         vector<int> ans;
//         for (const int& lake : rains) {
//             // it doesnt rain, we gotta push 
//             if (lake == 0) {
//                 // cout << "here " << endl;
//                 // cout << "0 case, stk size: " << stk.empty() << endl;
//                 while (!stk.empty()) {
//                     // auto x = stk.top();
//                     if (seen.contains(stk.top()) && seen[stk.top()] > 0) break;
//                     // cout << "stk popped" << endl;
//                     stk.pop();
//                 }
//                 // now the top of stack should be the one to dry out
//                 // if that exists
//                 if (!stk.empty()) {
//                     // cout << "up here" << endl;
//                     ans.push_back(stk.top());
//                     seen[stk.top()]--;
//                     stk.pop();
//                 // no more lakes needed to dry, arbitrary dry
//                 } else {
//                     // cout << "down here" <<endl;
//                     ans.push_back(1);
//                 }
//             }

//             // it does rain
//             else {
//                 if (seen[lake]) {
//                     cout << seen[lake] << endl;
//                     return {};
//                 }
//                 ans.push_back(-1);
//                 if (!stk.empty() && stk.top() == lake) {
//                     // cout << "popped: " << stk.top() << endl;
//                     // if (stk.top() != lake && seen[stk.top()] > 0) seen[stk.top()]--;   // resolved someone else
//                     stk.pop();
//                 }
//                 seen[lake]++;
//             }
//             PRINT(ans);
//         }

//         return ans;
//     }
// };