// Jan. 18th, 2025 (daily), Oct. 2nd, 2025

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++) {
            visited[row][0] = 1;
            visited[row][cols - 1] = 1;
            minHeap.push({heightMap[row][0], {row, 0}});
            minHeap.push({heightMap[row][cols - 1], {row, cols - 1}});
        }

        for (int col = 0; col < cols; col++) {
            visited[0][col] = 1;
            visited[rows - 1][col] = 1;
            minHeap.push({heightMap[0][col], {0, col}});
            minHeap.push({heightMap[rows - 1][col], {rows - 1, col}});
        }

        int res = 0;

        while (!minHeap.empty()) {
            int currentHeight = minHeap.top().first;
            int currentRow = minHeap.top().second.first;
            int currentCol = minHeap.top().second.second;
            minHeap.pop();

            int rowDirections[] = {-1, 0, 1, 0};
            int colDirections[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int nextRow = currentRow + rowDirections[i];
                int nextCol = currentCol + colDirections[i];

                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && !visited[nextRow][nextCol]) {
                    res += max(0, currentHeight - heightMap[nextRow][nextCol]);
                    minHeap.push({max(currentHeight, heightMap[nextRow][nextCol]), {nextRow, nextCol}});
                    visited[nextRow][nextCol] = 1;
                }
            }
        }

        return res;
    }
};



//         int rows = heightMap.size();
//         int cols = heightMap[0].size();

//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));

//         vector<vector<pair<int, int>>> ponds;

//         // create the ponds by finding bfs origin/target contenders
//         for (int i = 0; i < rows-2; ++i) {
//             for (int j = 0; j < cols; ++j) {
//                 if (visited[i][j]) continue;

//                 visited[i][j] = true;
//                 int curr = heightMap[i][j];

//                 // potential origin detected
//                 if (curr > heightMap[i+1][j]) {
//                     vector<pair<int, int>> pond = bfs({i,j}, visited, heightMap);
//                     if (pond.size() >= 4) ponds.push_back(pond);
//                 }
//             }
//         }

//         // process the ponds
//         int res = 0;

//         for (auto& pond : ponds) {
//             for (int i = 0; i < pond.size(); ++i) {
//                 cout << "{" << pond[i].first << ", " << pond[i].second << "} ||";
//             }
//             cout << endl;
//         }

//         for (auto& pond : ponds) {
//             int minWall = INT_MAX;
//             unordered_set<pair<int, int>, pair_hash> currPath;
//             for (int i = 0; i < pond.size(); ++i) {
//                 auto [x, y] = pond[i];
//                 currPath.insert(pond[i]);
//                 minWall = min(minWall, heightMap[x][y]);
//             }

//             // process the water
//             for (int i = 0; i < pond.size(); ++i) {
//                 auto [x, y] = pond[i];

//                 pair<int, int> currWater = {x,y+1};
//                 while (currPath.find(currWater) == currPath.end()) {
//                     auto [a, b] = currWater;
//                     if (a < 0 || a >= heightMap.size() || b < 0 || b >= heightMap[0].size()) break;

//                     int elevation = (minWall - heightMap[a][b]);
//                     if (elevation > 0) res += elevation % 1000000007;
//                     currPath.insert(currWater);
//                     visited[a][b] = true;
//                     currWater = {currWater.first, currWater.second+1};
//                 }
//             }
//         }

//         return res;
//     }

//     // TODO
//     vector<pair<int, int>> bfs(pair<int, int> origin, vector<vector<bool>>& visited, vector<vector<int>>& heightMap) {
//         queue<pair<int, int>> q;
//         vector<pair<int, int>> pond;
//         vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up
//         vector<pair<int, int>> waterSide = {{1, 0}, {0, -1}, {-1, 0}, {}};    // Below, Left, Above, Right

//         q.push(origin);
//         pond.push_back(origin);

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();

//             for (int i = 0; i < directions.size(); ++i) {
//                 auto [dx1, dy1] = directions[i];
//                 auto [dx2, dy2] = waterSide[i];

//                 int nx = x + dx1, ny = y + dy1;
//                 int rx = nx + dx2, ry = ny + dy2;

//                 // Check bounds and visited status
//                 if (nx >= 0 && nx < heightMap.size() && ny >= 0 && ny < heightMap[0].size() && 
//                 rx >= 0 && rx < heightMap.size() && ry >= 0 && ry < heightMap[0].size() && 
//                 !visited[nx][ny]) {
//                     // Check if the neighbor is valid (part of the pond)
//                     if (heightMap[rx][ry] < heightMap[nx][ny]) {
//                         visited[nx][ny] = true;
//                         q.push({nx, ny});
//                         pond.push_back({nx, ny});
//                         break;
//                     }
//                 }
//             }
//         }

//         return pond;
//     }

//     struct pair_hash {
//         template <typename T1, typename T2>
//         std::size_t operator()(const std::pair<T1, T2>& p) const {
//             return std::hash<T1>{}(p.first) ^ (std::hash<T2>{}(p.second) << 1);
//         }
//     };
// };