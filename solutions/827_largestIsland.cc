// Jan. 30th, 2025 (daily)

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        unordered_map<int, int> island_size;
        vector<vector<int>> island_id(n, vector<int>(n, -1));
        int island_counter = 0;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && island_id[i][j] == -1) {
                    int area = 0;
                    bfs_single({i, j}, area, island_id, grid, island_counter);
                    island_size[island_counter++] = area;
                    res = max(res, area);
                }
            }
        }

        if (res == 0) return 1;

        vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> unique_ids;
                    int possible_area = 1;

                    for (auto& [dx, dy] : dirs) {
                        int nx = i + dx, ny = j + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            int id = island_id[nx][ny];
                            if (unique_ids.insert(id).second) {
                                possible_area += island_size[id];
                            }
                        }
                    }
                    res = max(res, possible_area);
                }
            }
        }

        return res;
    }

    void bfs_single(const pair<int, int>& src, int& area, vector<vector<int>>& island_id, vector<vector<int>>& grid, int island_counter) {
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push(src);
        island_id[src.first][src.second] = island_counter;

        vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            area++;

            for (auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && island_id[nx][ny] == -1) {
                    island_id[nx][ny] = island_counter;
                    q.push({nx, ny});
                }
            }
        }
    }
};



// 64/75 tle brute force lol

// class Solution {
// public:
//     int largestIsland(vector<vector<int>>& grid) {
//         int res = 0;
//         int n = grid.size();

//         vector<vector<bool>> visited(n, vector<bool>(n, false));

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 0) visited[i][j] = true;
//                 else if (!visited[i][j]) res = max(res, bfs({i, j}, visited, grid));
//             }
//         }

//         if (res == 0) return 1;

//         return min(res, n*n);
//     }

//     queue<pair<int, int>> bfs_single(const pair<int, int>& src, int& area, vector<vector<bool>>& visited, vector<vector<int>>& grid) {

//         int n = visited.size();

//         queue<pair<int, int>> q1;
//         q1.push(src);

//         vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

//         queue<pair<int, int>> q2;

//         while (!q1.empty()) {
//             auto [x, y] = q1.front();
//             q1.pop();
//             if (!visited[x][y]) {
//                 visited[x][y] = true;
//                 area++;
//             }

//             for (auto& dir : dirs) {
//                 auto [dx, dy] = dir;
//                 int nx = x+dx, ny = y+dy;
//                 if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
//                     if (grid[nx][ny] == 1) q1.push({nx,ny});
//                     else if (grid[nx][ny] == 0) {
//                         // cout << "pushed here" << endl;
//                         q2.push({nx, ny});
//                     }
//                 }
//             }
//         }

//         return q2;
//     }

//     int bfs(const pair<int, int>& src, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
//         int n = visited.size();

//         int mx_area = 0;
//         queue<pair<int, int>> q2 = bfs_single(src, mx_area, visited, grid);
//         mx_area++;

//         vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

//         vector<vector<bool>> temp_visited;

//         int cur_max = mx_area;
//         while (!q2.empty()) {
//             // cout << "we reached here." << endl;
//             auto [x, y] = q2.front();
//             q2.pop();
            
//             int cur_area = mx_area;
//             visited[x][y] = true;
//             temp_visited = visited;
            
//             for (auto& dir : dirs) {
//                 auto [dx, dy] = dir;
//                 int nx = x+dx, ny = y+dy;
//                 if (nx >= 0 && nx < n && ny >= 0 && ny < n && !temp_visited[nx][ny]) {
//                     if (grid[nx][ny] == 1) {
//                         int additional = 0;
//                         bfs_single({nx, ny}, additional, temp_visited, grid);
//                         cur_area += additional;
//                     }
//                 }
//             }
//             cur_max = max(cur_max, cur_area);
//         }

//         return cur_max;
//     }
// };




    // int bfs(const pair<int, int>& src, vector<vector<bool>>& visited, vector<vector<int>>& grid) {

    //     int n = visited.size();

    //     int mx_area = 0;
    //     queue<pair<int, int>> q2 = bfs_single(src, mx_area, visited, grid);
    //     cout << mx_area << endl;
    //     mx_area++;

    //     vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    //     vector<vector<bool>> visited_nei = visited;

        

    //     int cur_max = mx_area;
    //     while (!q2.empty()) {
    //         // cout << "we reached here." << endl;
    //         auto [x, y] = q2.front();
    //         q2.pop();
    //         visited_nei[x][y] = true;

    //         for (auto& dir : dirs) {
    //             int bigger_area = mx_area;
    //             auto [dx, dy] = dir;
    //             int nx = x+dx, ny = y+dy;
    //             if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited_nei[nx][ny]) {
    //                 if (grid[nx][ny] == 1) {
    //                     bfs_single({nx, ny}, bigger_area, visited_nei, grid);
    //                     cur_max = max(cur_max, bigger_area);
    //                 }
    //             }
    //         }
    //     }

    //     return cur_max;
    // }
// };