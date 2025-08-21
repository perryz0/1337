// Aug. 20th, 2025

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> h(n,0);
        int ans = 0;

        for (int i=0; i<m; ++i) {
            // consecutive vertical heights
            for (int j=0; j<n; ++j)
                h[j] = (mat[i][j] ? h[j] + 1 : 0);

            // for each right boundary j, sweep left and acc
            for (int j=0; j<n; ++j) {
                int minH = INT_MAX;
                for (int k = j; k >= 0 && h[k] > 0; --k) {
                    minH = min(minH, h[k]);
                    ans += minH; // add rectangles with right=j, left=k
                }
            }
        }
        return ans;
    }
};
