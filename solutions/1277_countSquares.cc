// Aug. 19th, 2025
///nondp soln

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // first squares, then ps of squares
        vector<int> ps(301,0);
        for (int i=1; i<=300; ++i) ps[i]=i*i;
        for (int i=2; i<=300; ++i) ps[i]+=ps[i-1];

        // build 2D prefix sums S[r+1][c+1] = sum of matrix[0..r][0..c]
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> S(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; ++i) {
            int rowSum = 0;
            for (int j = 1; j <= n; ++j) {
                rowSum += matrix[i-1][j-1];
                S[i][j] = S[i-1][j] + rowSum;
            }
        }
        auto sumBlock = [&](int r, int c, int s) -> int {
            // block top-left (r,c) size s in matrix-indexing (0-based)
            int r2 = r+s, c2 = c+s;
            return S[r2][c2] - S[r][c2] - S[r2][c] + S[r][c];
        };

        // queue exploration over (i, j, s)
        struct Node { int i, j, s; };
        std::queue<Node> q;

        // seed: every 1-cell is a 1x1 square
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==1) q.push({i,j,1});
            }
        }

        int ans = 0;
        while (!q.empty()) {
            auto [i,j,s] = q.front(); q.pop();
            ans += 1;  // count the current s×s square at (i,j)

            int s2 = s+1;
            if (i + s2 <= m && j + s2 <= n) {
                // check if the (s+1)^2 block is full of 1s
                int need = ps[s2] - ps[s]; // equals (s+1)^2
                if (sumBlock(i, j, s2) == need) {
                    q.push({i, j, s2});
                }
            }
        }

        return ans;
    }
};




// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         vector<int> ps(301,0); // squares?
//         for (int i=1; i<=300; ++i) {
//             ps[i]=i*i;
//         }

//         // prefix sum for the total num of squares
//         for (int i=2; i<=300; ++i) {
//             ps[i]+=ps[i-1];
//         }

//         // layered bfs?
//         vector<pair<int,int>> dirs = {{0,1},{1,0},{1,1}};
//         int m=matrix.size(), n=matrix[0].size();
//         int ans=0;
//         vector<vector<bool>> vis(m, vector<bool>(n, false));
//         for (int i=0; i<m; ++i) {
//             for (int j=0; j<n; ++j) {
//                 if (matrix[i][j] == 0 || vis[i][j]) continue; 
//                 // otherwise layered bfs
//                 int largest=1;
//                 queue<pair<int,int>> q;
//                 q.push({i,j});
//                 vis[i][j]=true;
//                 while (!q.empty()) {

//                     bool broken=false;
//                     queue<pair<int,int>> nextRung;
//                     vector<vector<bool>> explore = vis;
//                     while (!q.empty()) {
//                         auto [x,y] = q.front();
//                         q.pop();

//                         for (const auto [dx,dy] : dirs) {
//                             int nx=x+dx, ny=y+dy;
//                             if (nx >= m || ny >= n || matrix[nx][ny] == 0) {
//                                 broken=true;
//                                 break;
//                             }
//                             if (explore[nx][ny]) continue;
                            
//                             // otherwise mark visited and add to queue
//                             explore[nx][ny]=true;
//                             nextRung.push({nx,ny});
//                         }
//                         if (broken) break;
//                     }

                    
//                     if (broken) {
//                         ans += ps[largest];
//                         break;
//                     }

//                     largest++;
//                     q = nextRung;
//                     vis = explore;
//                 }
//             }
//         }


//         return ans;
//     }
// };