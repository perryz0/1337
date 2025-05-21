// May 20th, 2025 (daily)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        unordered_set<int> r,c;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for (const int& row : r) {
            for (int j=0; j<n; ++j) {
                matrix[row][j] = 0;
            }
        }

        for (const int& col : c) {
            for (int i=0; i<m; ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};