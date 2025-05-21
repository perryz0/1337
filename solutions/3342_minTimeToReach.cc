// May 7th, 2025 (daily)

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        //dijkstras, no negative costs, greedy moves
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector(m, INT_MAX));
        priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<>> pq; // <cost, x,y, parity>

        // int runningTime = 0;
        vector<vector<bool>> v(n, vector(m, false));
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        // if (m>1) pq.push({max(1, moveTime[0][1] + 1), 0, 1});
        // if (n>1) pq.push({max(1, moveTime[1][0] + 1), 1, 0});
        pq.push({0,0,0,0});

        while (!pq.empty()) {
            auto [c,x,y,p] = pq.top(); pq.pop();
            if (v[x][y]) continue;
            v[x][y] = true;

            if (x == n-1 && y == m-1) break;

            for (auto [dx, dy] : dirs) {
                int nx = x+dx, ny = y+dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !v[nx][ny]) {
                    int nc = (p == 0) ? 1:2;
                    int np = 1-p;
                    int arrival = max(c+nc, moveTime[nx][ny] + nc);
                    if (arrival < minTime[nx][ny]) {
                        minTime[nx][ny] = arrival;
                        pq.push({arrival, nx, ny, np});
                    }
                }
            }
        }


        return minTime[n-1][m-1];
    }
};