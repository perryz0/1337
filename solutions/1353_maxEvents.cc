// July 6th, 2025

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<pair<int,int>> e;
        int maxd=1, mind=INT_MAX;
        for (const auto& ev : events) {
            e.push_back({ev[0],ev[1]});
            maxd=max(maxd,ev[1]);
            mind=min(mind, ev[0]);
        }
        sort(e.begin(), e.end());
        int n=e.size();

        priority_queue<int, vector<int>, greater<>> pq; // minpq

        // go through every day
        int eventIdx=0;
        int ans=0;
        for (int i=mind; i<=maxd; ++i) {
            while (eventIdx < n && e[eventIdx].first <= i) {
                // cout << eventIdx << endl;
                pq.push(e[eventIdx].second);    // push all the endDays for greedy
                eventIdx++;
            }
            while (!pq.empty() && pq.top() < i) pq.pop();
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;


        // // count all days with attends
        // int ans=0;
        // for (int i=1;i<d+1; ++i) {
        //     cout << "day " << i << ": " << days[i] << endl;
        //     ans+=days[i];
        // }

        // return ans;
    }
};


        // a little confusing, so we enumerate every day instead
        // int curStart = e[0].first, curEnd = e[0].second;
        // int curCap = e[0].second-e[0].first+1;
        // int available = curCap-1;
        // cout << available << endl;
        // int ans=1;
        // int n=e.size();
        // for (int i=1; i<n; ++i) {
        //     auto [candStart, candEnd] = e[i];
        //     if (available>0) { // check can watch
        //         ans++;
        //         available--;
        //         // adjust available window size
        //         available -= (candStart - curStart);
        //         available += (candEnd - curEnd);
        //         curStart = candStart;
        //         curEnd = candEnd;
        //     }
        // }

            // while (lastAvailable <= curEnd) {
            //     if (!days[lastAvailable]) {
            //         days[lastAvailable++] = true;
            //         break;
            //     }
            //     ++lastAvailable;
            // }



        // // int d=e[n-1].second; // not sure if this is invariant here

        // // day 0 must be the first event after sort
        // vector<bool> days(d+1,0);
        // // days[0] = true;
        // days[e[0].first] = true;
        // // int firstAvailable=e[0].first+1;
        // // int lastAvailable=
        // // cout << lastAvailable << endl;
        // for (int i=1; i<n; ++i) {   // start from event1
        //     auto [curStart, curEnd] = e[i];

        // }