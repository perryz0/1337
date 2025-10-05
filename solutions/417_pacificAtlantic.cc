// Oct. 4th, 2025

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        // bfs towards pacific + bfs towards atlantic
        set<pair<int,int>> P,A;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        for (int i=0; i<m; ++i) {
            vis[i][0]=true;
            P.insert({i,0});
            q.push({i,0});
        }
        for (int j=0; j<n; ++j) {
            vis[0][j]=true;
            P.insert({0,j});
            q.push({0,j});
        }

        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}}; // MOVING down/right for PACIFIC

        while (!q.empty()) {
            auto [x,y] = q.front();
            int h = heights[x][y];
            q.pop();
            for (const auto& [dx,dy] : dirs) {
                int nx=x+dx, ny=y+dy;
                if (nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && heights[nx][ny] >= h) {
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                    P.insert({nx,ny});
                }
            }
        }

        // dirs = {{0,-1},{-1,0},{0,1},{1,0}};   // up/left for atl
        vis = vector<vector<bool>>(m, vector<bool>(n, false));


        for (int i=0; i<m; ++i) {
            vis[i][n-1]=true;
            A.insert({i,n-1});
            q.push({i,n-1});
        }
        for (int j=0; j<n; ++j) {
            vis[m-1][j]=true;
            A.insert({m-1,j});
            q.push({m-1,j});
        }

        while (!q.empty()) {
            auto [x,y] = q.front();
            int h = heights[x][y];
            q.pop();
            for (const auto& [dx,dy] : dirs) {
                int nx=x+dx, ny=y+dy;
                if (nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && heights[nx][ny] >= h) {
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                    A.insert({nx,ny});
                }
            }
        }

        vector<vector<int>> ans;
        for (const pair<int,int>& p : P) {
            if (A.contains(p)) ans.push_back({p.first, p.second});
        }

        return ans;
    }
};