// Jan. 19th, 2025 (daily)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int, pair<int, int>> mat_map;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) mat_map[mat[i][j]] = {i, j};

        vector<int> rowTracker(m, n);
        vector<int> colTracker(n, m);

        for (int i = 0; i < arr.size(); ++i) {
            auto& [x, y] = mat_map.find(arr[i])->second;
            if (--rowTracker[x] == 0) return i;
            if (--colTracker[y] == 0) return i;
        }

        return -1;
    }
};