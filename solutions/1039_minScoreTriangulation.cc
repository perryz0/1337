// Sep. 28th, 2025

class Solution {
private:
    int dp[55][55];

    int solve(vector<int>& values, int i, int j) {
        if (j-i < 2) return 0;   // fewer than 3 vertices -> no triangulation
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i+1; k < j; ++k) {
            int cost = values[i]*values[j]*values[k] + solve(values,i,k) + solve(values,k,j);
            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        // two challenges:
        // 1. greedily pick the shortest 2 available vertices
        // 2. the remaining vertex should be the next available vertex that still makes it a valid triangle
        memset(dp, -1, sizeof(dp));
        return solve(values, 0, values.size()-1);
    }
};