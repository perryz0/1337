// July 23rd, 2025
// cheat day yes

class Solution {
public:
    int n;
    vector<vector<int>> graph;
    vector<int> xorSubtree, in, out;
    int timer = 0;

    void dfs(int u, int parent, const vector<int>& nums) {
        xorSubtree[u] = nums[u];
        in[u] = timer++;
        for (int v : graph[u]) {
            if (v == parent) continue;
            dfs(v, u, nums);
            xorSubtree[u] ^= xorSubtree[v];
        }
        out[u] = timer++;
    }

    bool isAncestor(int u, int v) {
        // is u an ancestor of v?
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        graph.assign(n, vector<int>());
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        xorSubtree.resize(n);
        in.resize(n);
        out.resize(n);
        timer = 0;
        dfs(0, -1, nums);
        int totalXor = xorSubtree[0];

        int res = INT_MAX;

        // try every pair of nodes u, v representing cut edges
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int x, y, z;
                if (isAncestor(u, v)) {
                    // v is in u's subtree
                    x = xorSubtree[v];
                    y = xorSubtree[u] ^ xorSubtree[v];
                    z = totalXor ^ xorSubtree[u];
                } else if (isAncestor(v, u)) {
                    // u is in v's subtree
                    x = xorSubtree[u];
                    y = xorSubtree[v] ^ xorSubtree[u];
                    z = totalXor ^ xorSubtree[v];
                } else {
                    // disjoint subtrees
                    x = xorSubtree[u];
                    y = xorSubtree[v];
                    z = totalXor ^ xorSubtree[u] ^ xorSubtree[v];
                }
                int currMax = max({x, y, z});
                int currMin = min({x, y, z});
                res = min(res, currMax - currMin);
            }
        }
        return res;
    }
};
