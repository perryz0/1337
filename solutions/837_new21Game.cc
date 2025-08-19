// Aug. 16th, 2025
// kinda got cooked

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

        // guaranteed that the jump AFTER n is IMPOSSIBLE
        if (k-1+maxPts <= n) return 1;

        // edge case: if k == 0, Alice stops immediately at 0 points
        if (k == 0) return 1;

        // then just dp the {k-1, k-2, ... k-x}, where k-x is the smallest possible PREV step that can still jump to n+1 
        // DP idea:
        // dp[i] = probability to end up with EXACTLY i points.
        // For i < k we are still drawing; for i >= k we stop.
        // Transition (for i >= 1):
        //   dp[i] = (dp[i-1] + dp[i-2] + ... + dp[i-maxPts]) / maxPts, but only summing terms where (i-1 - t) < k
        // Use a sliding window "window" that holds sum of last maxPts dp[j] where j < k.

        std::vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double window = 0, ans =0;   // sum of dp[j] for j in [i-maxPts, i-1] intersected with j < k
        // double ans = 0;

        for (int i=1; i<=n; ++i) {
            // if (i-1) was a state where we still draw (< k), it contributes to window
            if (i-1 < k) window += dp[i-1];

            // drop the term that falls out of the last maxPts range and was also a "drawing" state
            int dropIdx = i-1-maxPts;
            if (dropIdx >= 0 && dropIdx < k) window -= dp[dropIdx];

            dp[i] = window / maxPts;

            // once i >= k, it's a terminal score; accumulate into answer if i <= n (we're iterating to n anyway)
            if (i >= k) ans += dp[i];
        }

        return ans;
    }
};
