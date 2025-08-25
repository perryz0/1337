// Aug. 24th, 2025

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        bool up=true;
        int m=mat.size(), n=mat[0].size();

        int i=0, j=0;
        while (i != m-1 || j != n-1) {
            ans.push_back(mat[i][j]);

            // first decide if its time to switch dirs
            if (((i == 0 || j==n-1) && up) || ((j==0 || i==m-1) && !up)) {
                // if up, we must first try j+1 (then i+1 if hit the edge); if down, we must do i+1 (and then j+1)
                if (up) {
                    if (j+1 < n) {
                        j++;
                    } else {
                        i++;
                    }
                } else {
                    if (i+1 < m) {
                        i++;
                    } else {
                        j++;
                    }
                }
                up = !up;   // flip directions
            }
            // not switching dirs, we keep going diagonally
            else {
                if (up) {
                    i--;
                    j++;
                } else {
                    i++;
                    j--;
                }
            }
        } 

        // last one is always the bottom right
        ans.push_back(mat[m-1][n-1]);

        return ans;
    }
};