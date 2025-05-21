// May 7th, 2025 (daily)

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        //dijkstras, no negative costs, greedy moves
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector(m, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq; // <cost, x,y>

        // int runningTime = 0;
        vector<vector<bool>> v(n, vector(m, false));
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        // if (m>1) pq.push({max(1, moveTime[0][1] + 1), 0, 1});
        // if (n>1) pq.push({max(1, moveTime[1][0] + 1), 1, 0});
        pq.push({0,0,0});

        while (!pq.empty()) {
            auto [c,x,y] = pq.top(); pq.pop();
            if (v[x][y]) continue;
            v[x][y] = true;

            if (x == n-1 && y == m-1) return c;

            for (auto [dx, dy] : dirs) {
                int nx = x+dx, ny = y+dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !v[nx][ny]) {
                    int arrival = max(c+1, moveTime[nx][ny] + 1);
                    if (arrival < minTime[nx][ny]) {
                        minTime[nx][ny] = arrival;
                        pq.push({arrival, nx, ny});
                    }
                }
            }
        }


        return minTime[n-1][m-1];
    }
};













// time simulation, bad complexity bc o(nmlognm + max(moveTime)), max might be 10e9
// class Solution {
// public:
//     int minTimeToReach(vector<vector<int>>& moveTime) {
//         //dijkstras, no negative costs, greedy moves
//         int n = moveTime.size(), m = moveTime[0].size();
//         vector<vector<int>> minTime(n, vector(m, INT_MAX));
//         priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq; // <cost, x,y>

//         int runningTime = 0;
//         vector<vector<bool>> v(n, vector(m, false));
//         vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

//         if (m>1) pq.push({max(1, moveTime[0][1] + 1), 0, 1});
//         if (n>1) pq.push({max(1, moveTime[1][0] + 1), 1, 0});

//         while (!v[n-1][m-1]) {
//             while (!pq.empty() && get<0>(pq.top()) <= runningTime) {
//                 auto [c, x, y] = pq.top(); pq.pop();
//                 if (v[x][y]) continue;
//                 v[x][y] = true;
//                 minTime[x][y] = c;

//                 for (auto [dx, dy] : dirs) {
//                     int nx = x + dx, ny = y + dy;
//                     if (nx >= 0 && ny >= 0 && nx < n && ny < m && !v[nx][ny]) {
//                         int arrival = max(c + 1, moveTime[nx][ny] + 1);
//                         if (arrival < minTime[nx][ny]) {
//                             minTime[nx][ny] = arrival;
//                             pq.push({arrival, nx, ny});
//                         }
//                     }
//                 }
//             }
//             runningTime++;
//         }


//         return minTime[n-1][m-1];
//     }
// };