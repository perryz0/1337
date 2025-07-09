// July 8th, 2025

class Solution {
private:
    void ARR(const vector<int>& a) {
        cout << "[";
        for (const int& v : a) {
            cout << v << " ";
        }
        cout << "]" << endl;
    }

public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // startTime[i]+a must imply endTime[i]+a
        // slide over the gaps
        // n events, k moves
        // if we count zero-gaps (no gap between two events), there are n+1 gaps
        // and thus when we greedily shift events, there will be k+1 gaps joined
        int n=startTime.size();
        vector<int> g(n+1, 0);
        g[0] = startTime[0];    // start_of_first - 0th_hour (first event)
        for (int i=1; i<n; ++i) {
            g[i] = startTime[i]-endTime[i-1];
        }
        g[n] = eventTime-endTime[n-1];  // last event

        // ARR(g);

        // after shifting k events, there will be n-k meetings unchanged
        int curLargeGap=0;
        for (int i=0; i<k+1; ++i) {
            curLargeGap+=g[i];  // the first continuous free time (k+1 Ngaps joined)
        }
        int ans=curLargeGap;

        // cout << "HERE" << endl;

        // try all possible gapSum combinations
        for (int i=k+1; i<n+1; ++i) {
            curLargeGap -= g[i-(k+1)];    // remove the first gap in currWindow
            curLargeGap += g[i];            // add the last gap in currWindow
            ans=max(ans, curLargeGap);
        }

        return ans;
    }
};


        // // first convert into more readable data
        // vector<bool> freeIntervals(eventTime, 0);
        // // interval[0] = 0->1 interval, etc...
        // int startptr=0;
        // for (int interval=0; interval<eventTime; ++interval) {
        //     if (interval == endTime[startptr]) startptr++; // consider advancing the startptr
        //     if (interval < startTime[startptr]) {
        //         // if (startptr == 0 || interval >= endTime[startptr-1]) {
        //         // then we consider this to be current free time 
        //         freeIntervals[interval] = 1;
        //         // }
        //     }
        // }

        // // 

        // // ARR(freeIntervals);

        // return 0;