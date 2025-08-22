// Aug. 21st, 2025

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minR=INT_MAX;
        int minC=INT_MAX;
        int maxR=-1;
        int maxC=-1;

        int m=grid.size(), n=grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    minR=min(minR, i);
                    minC=min(minC, j);
                    maxR=max(maxR, i);
                    maxC=max(maxC, j);
                }
            }
        }

        return (maxR == -1 && maxC == -1) ? 0 : (maxR-minR+1)*(maxC-minC+1);
    }
};