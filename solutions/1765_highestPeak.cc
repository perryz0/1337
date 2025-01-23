// Jan. 21st, 2025 (daily)

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int rows = isWater.size();
        int cols = isWater[0].size();
        
        queue<pair<int, int>> waterCells;
        vector<vector<int>> res(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; ++i) for (int j = 0; j < cols; ++j) if (isWater[i][j] == 1) {
            waterCells.push({i, j});
            res[i][j] = 0;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};   // Down, Up, Right, Left

        // multi source bfs
        while (!waterCells.empty()) {
            auto [x, y] = waterCells.front();
            waterCells.pop();

            for (auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && res[nx][ny] == -1) {
                    res[nx][ny] = res[x][y]+1;
                    waterCells.push({nx, ny});
                }
            }
        }

        return res;
    }
};