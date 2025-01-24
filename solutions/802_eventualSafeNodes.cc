// Jan. 24th, 2025 (daily)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();

        vector<bool> cyclic(n, false);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            unordered_set<int> path;
            if (graph[i].empty()) res.push_back(i);
            else if (!dfs(i, graph, path, cyclic, visited)) res.push_back(i);
        }

        return res;
    }

    bool dfs(int node, vector<vector<int>>& graph, unordered_set<int>& path, vector<bool>& cyclic, vector<bool>& visited) {
        if (cyclic[node]) return true;
        if (visited[node]) return false;
        if (path.find(node) != path.end()) { 
            cyclic[node] = true;
            return true; 
        }

        path.insert(node);
        for (int& neighbor : graph[node]) {
            if (dfs(neighbor, graph, path, cyclic, visited)) {
                cyclic[node] = true;
                return true;
            }
        }
        path.erase(node);   // backtrack
        visited[node] = true;
        return false;
    }
};
