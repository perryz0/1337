// May 25th, 2025 (daily)

class Solution {
private:
    vector<vector<int>> dp;
    vector<unordered_set<int>> adj;
    vector<int> visited;
    bool hasCycle = false;
    string colors;

    void dfs(int u) {
        visited[u] = 1;
        for (int v : adj[u]) {
            if (visited[v] == 1) {
                hasCycle = true;
                return;
            } else if (visited[v] == 0) {
                dfs(v);
                if (hasCycle) return;
            }
            for (int c = 0; c < 26; ++c) {
                dp[u][c] = max(dp[u][c], dp[v][c]);
            }
        }
        dp[u][colors[u]-'a']++;
        visited[u] = 2;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length(), m = edges.size();
        dp.assign(n, vector<int>(26, 0));    // dp[u][c] := the maximum count of vertices with color c of any path starting from vertex u
        adj.assign(n, {});                   // adjacency list
        visited.assign(n, 0);                // 0 = unvisited, 1 = visiting, 2 = visited
        this->colors = colors;

        // toposort
        queue<int> q;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].insert(v);
        }
        for (int i = 0; i < n; ++i) if (adj[i].empty()) q.push(i);
        if (q.empty()) return -1;

        // dfs from every single node with indegree 0, store the colors in dp[u][c], so we prevent traversing more than twice?
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) dfs(i);
            if (hasCycle) return -1;
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int c = 0; c < 26; ++c)
                res = max(res, dp[i][c]);
        return res;
    }
};
