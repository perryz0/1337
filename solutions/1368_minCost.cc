// Jan. 17th, 2025 (daily)

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> minCosts(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> pairs_queue;
        pairs_queue.push({0,0});
        minCosts[0][0] = 0;

        // directions (idx 0 is dummy)
        vector<pair<int, int>> directions = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!pairs_queue.empty()) {
            int x = pairs_queue.front().first;
            int y = pairs_queue.front().second;
            int curr_dir = grid[x][y];
            pairs_queue.pop();

            for (int i = 1; i < directions.size(); ++i) {
                int currCost = minCosts[x][y];
                auto [dx, dy] = directions[i];
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (i != curr_dir) currCost = currCost+1;
                    if (currCost < minCosts[nx][ny]) {
                        minCosts[nx][ny] = currCost;
                        pairs_queue.push({nx, ny});
                    }
                }
            }
        }

        return minCosts[rows-1][cols-1];
    }
};