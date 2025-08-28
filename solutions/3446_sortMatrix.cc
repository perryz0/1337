// Aug. 27th, 2025

class Solution {
private:
    void PRINT(const vector<vector<int>>& vec) {
        cout << "---------------------------" << endl;
        for (const vector<int>& row : vec) {
            for (const int& e : row) {
                cout << e << " ";
            }
            cout << endl;
        }
    }

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n, vector<int>(n, -1e6));

        // first process top right
        for (int a=n-1; a>=1; --a) {
            int j=a, i=0;
            vector<int> diag;
            for (; j<n && i<n; ++j, ++i) {
                diag.push_back(grid[i][j]);
            }
            sort(diag.begin(), diag.end());
            // cout << "For diag " << a << ": [";
            // for (const auto& e : diag) cout << e << " ";
            // cout << endl;
            j=a, i=0;
            int it=0;
            for (; j<n && i<n; ++j && ++i) {
                ans[i][j]=diag[it];
                ++it;
            }
        }

        // PRINT(ans);

        // bottom left
        for (int a=0; a<n; ++a) {
            int j=0, i=a;
            vector<int> diag;
            for (; j<n && i<n; ++j, ++i) {
                diag.push_back(grid[i][j]);
            }
            sort(diag.rbegin(), diag.rend());
            // cout << "For diag " << a << ": [";
            // for (const auto& e : diag) cout << e << " ";
            // cout << endl;
            j=0, i=a;
            int it=0;
            for (; j<n && i<n; ++j && ++i) {
                ans[i][j]=diag[it];
                ++it;
            }
        }

        return ans;
    }
};