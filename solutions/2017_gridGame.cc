// Jan. 20th, 2025 (daily)

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long runningTop = 0;
        for (int i = 1; i < n; ++i) runningTop += grid[0][i];

        long long runningSmallestMax = runningTop;
        long long runningBottom = 0;
        
        for (int i = 1; i < n; ++i) {

            runningBottom += grid[1][i-1];
            runningTop -= grid[0][i];

            runningSmallestMax = min(runningSmallestMax, max(runningBottom, runningTop));
        }

        return runningSmallestMax;
    }
};