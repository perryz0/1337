// July 9th, 2025

class Solution {
private:
    void ARR(const vector<int>& a) {
        cout << "[";
        for (const int& v : a) {
            cout << v << " ";
        }
        cout << "]" << endl;
    }

    void ARRp(const vector<pair<int,int>>& a) {
        cout << "[";
        for (auto [v,i] : a) {
            cout << "{" << v << " " << i << "}" << " ";
        }
        cout << "]" << endl;
    }

public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        // relative order can be different
        int n=startTime.size(); // nEvents
        vector<int> g1(n+1, 0);
        g1[0] = startTime[0];
        for (int i=1; i<n; ++i) {
            g1[i] = startTime[i] - endTime[i-1];
        }
        g1[n] = eventTime-endTime[n-1];
        // since we only move one event, the two gaps must still be continuous to acctually join gaps
        // gap[i] corresponds startTime[i] - endTime[i-1];
        if (n==1) return g1[0]+g1[1];

        // nGapsResolved per window = 2, since k=1

        priority_queue<pair<int,int>> pq;
        for (int i=0; i<n+1; ++i) pq.push({g1[i],i});
        // unordered_map<int,vector<int>> freqs;
        // for (const int& g : g1) freqs[g]
        vector<pair<int, int>> temp;
        int curr=g1[0]+g1[1];
        int ans=curr;
        while (!pq.empty() && (pq.top().second == 0 || pq.top().second == 1)) {
            // cout << pq.top().first << endl;
            temp.push_back(pq.top());
            pq.pop();
        }

        if (!pq.empty() && pq.top().first >= endTime[0]-startTime[0]) ans += (endTime[0]-startTime[0]);

        for (const auto& p : temp) pq.push(p);
        temp.clear();

        // slide k=2 windows in gaps
        // Slide window of 2 gaps, try moving the sandwiched event into best non-adjacent gap
        for (int i = 2; i <= n; ++i) {
            curr = curr - g1[i-2] + g1[i];
            int evt = i-1;
            int duration = endTime[evt] - startTime[evt];

            while (!pq.empty() && (pq.top().second == i-1 || pq.top().second == i)) {
                temp.push_back(pq.top());
                pq.pop();
            }

            // cout << pq.top().first << " vs. " << duration << endl;
            // cout << "ans is already: " << ans << endl;

            if (!pq.empty() && pq.top().first >= duration) {
                ans = max(ans, curr+duration);
            } else {
                ans = max(ans, curr);
            }

            for (const auto& p : temp) pq.push(p);
            temp.clear();
        }

        return ans;
    }
};






        // vector<pair<int,int>> g2(n+1, {0,0});
        // for (int i=0; i<n+1; ++i) g2[i]={g1[i],i};
        // sort(g2.begin(), g2.end());

        // ARRp(g2);

        // int MAX=g2[n].first;
        // int ans=0;
        // for (int i=n-1; i>n-4 && i>=0; --i) {
        //     int cur = (abs(g2[n].second-g2[i].second) == 1) ? MAX+g2[i].first : MAX+g2[i].first+1;
        //     ans=max(ans,cur);
        // }

        // return ans;