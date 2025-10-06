// Oct. 5th, 2025

using tiii = tuple<int,int,int>;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = 0;
        priority_queue<tiii, vector<tiii>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0]=true;
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        while (!pq.empty()) {
            auto [e,x,y] = pq.top();
            pq.pop();
            ans=max(ans,e);
            if (x == m-1 && y == n-1) return ans;
            for (const auto& [dx,dy] : dirs) {
                int nx=x+dx, ny=y+dy;
                if (nx<m && nx>=0 && ny<n && ny>=0 && !vis[nx][ny]) {
                    vis[nx][ny]=true;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }

        return ans;
    }
};