// July 7th, 2025

class Solution {
private:
    // vector<int> ans;
    vector<vector<int>> dp;

public:
    int maxValue(vector<vector<int>>& events, int k) {
        // sort, then binsearch
        // ans=0;
        int n=events.size();
        sort(events.begin(), events.end());

        // prune to remove potential overlaps that mustnt be considered??
        // optimization, later

        // knapsack + binsearch (strictly smaller or greater), LHS with endDay, RHS with startDay
        dp = vector<vector<int>>(n+1, vector<int>(k+1, 0));
        // for (int j=0; j<n; ++j) dp[0][j] = events[j][2];

        vector<int> starts;
        for (auto e : events) starts.push_back(e[0]);
        for (int i=n-1; i>=0; --i) {
            auto e = events[i];
            int start = e[0], end = e[1], val = e[2];

            // bs for next possible event
            int nextIDX = upper_bound(starts.begin(), starts.end(), end) - starts.begin();

            // choose/not choose
            for (int nEvents = 1; nEvents<=k; ++nEvents) {
                dp[i][nEvents] = max(dp[i+1][nEvents], val + dp[nextIDX][nEvents-1]);
            }
        }

        return dp[0][k];
    }
};