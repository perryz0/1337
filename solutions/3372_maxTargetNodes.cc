// May 27th, 2025 (daily)

class Solution {
private:
    vector<vector<int>> adj;

    // reachable nodes with k
    int dfs(int node, int parent, int depth, int k, const vector<vector<int>>& graph) {
        if (depth > k) return 0;
        int count = 1;  // include self
        for (int nei : graph[node]) {
            if (nei != parent) {
                count += dfs(nei, node, depth + 1, k, graph);
            }
        }
        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        // build the two trees
        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        int maxCount2 = 0;
        for (int j=0; j<m; ++j) {
            int count = dfs(j, -1, 0, k-1, tree2);
            maxCount2 = max(maxCount2, count);
        }

        // dfs from every node in tree1
        vector<int> ans(n);
        for (int i=0; i<n; ++i) {
            int count1 = dfs(i, -1, 0, k, tree1);
            ans[i] = count1 + maxCount2;
        }

        return ans;
    }
};
