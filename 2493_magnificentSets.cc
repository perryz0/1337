// Jan. 28th, 2025 (daily)
// learned bipartite graph checking

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n+1);

        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        unordered_set<int> visited;

        int res = 0;
        for (int i = 1; i < n+1; ++i) {

            // check if cur node was processed as part of some component before
            if (visited.find(i) != visited.end()) continue;

            // no, so we start a new component
            visited.insert(i);
            unordered_map<int, int> comp;
            if (bfs(i, comp, adj, visited) == -1) return -1;        // graph is not bipartite (has odd length cycle)

            int comp_max = 0;
            for (const auto& src : comp) {
                unordered_map<int, int> cur_dist;
                comp_max = max(comp_max, bfs(src.first, cur_dist, adj, visited));
            }

            res += comp_max;
        }

        return res;
    }

    int bfs(int src, unordered_map<int, int>& dist, vector<unordered_set<int>>& adj, unordered_set<int>& visited) {
        queue<pair<int, int>> q;    // (node, group)
        q.push({src, 1});
        dist[src] = 1;

        while (!q.empty()) {
            auto [node, length] = q.front();
            q.pop();

            for (const int& nei : adj[node]) {
                if (dist.contains(nei)) {
                    if (dist[nei] == length) return -1;     // two neighbors in same bfs depth, so not bipartite
                    continue;
                }
                q.push({nei, length + 1});
                dist[nei] = length + 1;
                visited.insert(nei);
            }
        }

        int mx = 0;
        for (const auto& node : dist) mx = max(mx, node.second);

        return mx;
    }
};





        // brute force construction attempt, dt it works tho
        // vector<unordered_set<int>> groups;
        // vector<int> degree(n+1, 0);
        // vector<unordered_set<int>> adj(n+1);

        // // find degrees for each node, adj for bidirectional edges
        // for (auto& edge : edges) {
        //     degree[edge[0]]++;
        //     degree[edge[1]]++;
        //     adj[edge[0]].insert(edge[1]);
        //     adj[edge[1]].insert(edge[0]);
        // }

        // // first-pass: cons g1 -> g3. nodes with highest degs are in the middle

        // // reverse-pass: check if we can take nodes from g2 -> g1 to create new groups beyond g3

        // return groups.size();