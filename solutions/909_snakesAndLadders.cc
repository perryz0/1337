// May 30th, 2025 (daily)

class Solution {
private:
    int steps;
    int n;
    vector<vector<int>> b;
    vector<bool> vis;

    int getCell(int r, int c) {
        int row = n-1-r;
        int col = (row % 2 == 0) ? c : (n-1-c);
        return row * n + col + 1;
    }

    pair<int,int> getCoords(int cell) {
        int row = n - 1 - (cell - 1) / n;
        int rem = (cell - 1) % n;
        int col = ((n-1 - row) % 2 == 0) ? rem : (n-1 - rem);
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vis.assign(n*n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front(); q.pop();
            if (curr == n * n) return steps;

            for (int i=1; i<=6 && curr+i <= n*n; ++i) {
                int next = curr + i;
                auto [r,c] = getCoords(next);
                if (board[r][c] != -1) next = board[r][c];

                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};




            // 13 = n*(n-(x+1))+y+1 = 6*(6-4)+(0+1) = 12+1 = 13
            // 12 = n*(n-(x+1))+(n-y) = 6*(6-5)+(6-0) = 6+6 = 12
            // 1 = n*(n-(x+1))+y+1 = 6*(6-6)+(0+1) = 1



    // boustrophedon
    // n-1 row is <----
    // nth row is ---->



        // // bool dir=n%2;   // parity
        // pair<int,int> curr = {n,0};
        // while (curr.first != 0 && curr.second != 0) {
        //     steps++;

        //     // // --->
        //     // if (!dir) {

        //     // }

        //     // // <---
        //     // else {

        //     // }

        //     // condition that gets stuck (no snake)
        //     pair<int,int> tmp = curr;

        //     bfs(curr);
            
        //     // condition that gets stuck (no snake), visited, not modified
        //     if (tmp == curr) return -1;
        // }

        // return steps;