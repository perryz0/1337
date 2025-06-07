// June 7th, 2025 (daily)

class Solution {
public:
    string clearStars(string s) {
        // minheap
        int n = s.length();
        priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> pq;
        // stack<char> stk;
        // for (int i=0; i<n; ++i) {
        //     if (s[i] != '*') pq.push({s[i], -i});    // maximize the index greedily for topk extracts
        //     // stk.push(s[i]);
        // }

        // cout << pq.top().first << "," << pq.top().second << endl;

        vector<int> rm;
        for (int i=0; i<n; ++i){
        // while (!stk.empty()) {
            // char c = stk.top();
            // stk.pop();

            char c = s[i];

            if (c != '*') {
                pq.push({s[i], -i});
                continue;
            }

            // cout << stk.size() << endl;

            rm.push_back(i);

            vector<pair<char,int>> t;
            while (!pq.empty() && (-1)*pq.top().second > i) {
                // cout << pq.top().first << "," << pq.top().second << endl;
                t.push_back(pq.top());
                pq.pop();
            }

            rm.push_back((-1)*pq.top().second);

            pq.pop();

            for (auto p : t) pq.push(p);

            // cout << pq.top().first << "," << pq.top().second << endl;    
        }

        // for (int& r : rm) cout << r << endl;

        // construct ans from the removal indices
        // reverse(rm.begin(), rm.end());
        sort(rm.begin(), rm.end());
        string ans;
        // int it=rm.size()-1;
        int it=0;
        for (int i=0; i<n; ++i) {
            if (it < rm.size() && rm[it] == i) {
                // cout << it << endl;
                it++;
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};