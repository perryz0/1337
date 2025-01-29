// Jan. 27th, 2025 (daily)

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int max_fish = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};   // Down, Up, Right, Left

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) max_fish = max(max_fish, bfs(grid, visited, {i, j}, dirs));
            }
        }

        return max_fish;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, pair<int, int> start, vector<pair<int, int>>& dirs) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push(start);

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (visited[x][y]) continue;

            visited[x][y] = true;
            cnt += grid[x][y];

            for (auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] > 0) q.push({nx, ny});
            }
        }
        
        return cnt;
    }
};