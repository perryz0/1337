// May 28th, 2025 (daily)

class Solution {
private:
    // color dfs to label even (0) and odd (1) depths
    void dfs_color(int node, int parent, int depth, const vector<vector<int>>& graph, vector<int>& color, int& white, int& black) {
        color[node] = depth % 2;
        if (color[node] == 0) white++;
        else black++;
        for (int nei : graph[node]) {
            if (nei != parent) {
                dfs_color(nei, node, depth + 1, graph, color, white, black);
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

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

        // color dfs for both trees
        vector<int> color1(n), color2(m);
        int white1 = 0, black1 = 0;
        int white2 = 0, black2 = 0;
        dfs_color(0, -1, 0, tree1, color1, white1, black1);
        dfs_color(0, -1, 0, tree2, color2, white2, black2);

        int maxCount2 = max(white2, black2);

        // dfs from every node in tree1
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int count1 = (color1[i] == 0 ? white1 : black1);
            ans[i] = count1 + maxCount2;
        }

        return ans;
    }
};
