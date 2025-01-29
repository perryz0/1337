// Jan. 29th, 2025 (daily)
// learned union find

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        for (int i = 0; i < n+1; ++i) parent[i] = i;
        vector<int> rank(n+1, 1);

        for (auto& edge : edges) if (!unionF(edge[0], edge[1], rank, parent)) return {edge[0], edge[1]};

        return {};
    }

    int find(int& n, vector<int>& parent) {
        if (n != parent[n]) parent[n] = find(parent[n], parent);

        return parent[n];
    }

    bool unionF(int& n1, int& n2, vector<int>& rank, vector<int>& parent) {
        int p1 = find(n1, parent), p2 = find(n2, parent);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) parent[p2] = p1;
        else parent[p1] = p2;

        return true;
    }
};






        // kahn's
        // int n = edges.size();
        // vector<int> indegree(n+1, 0);
        // unordered_map<int, vector<int>> graph;

        // for (auto& edge : edges) {
        //     graph[edge[0]].push_back(edge[1]);
        //     indegree[edge[1]]++;
        // }

        // queue<int> q;

        // for (int i = 1; i <= n; ++i) if (indegree[i] == 0) q.push(i);

        // while (!q.empty()) {
        //     int node = q.front();
        //     q.pop();
        //     for (int neighbor : graph[node]) {
        //         indegree[neighbor]--;
        //         if (indegree[neighbor] == 0) q.push(neighbor);
        //     }
        // }

        // for (int i = n - 1; i >= 0; --i) {
        //     if (indegree[edges[i][1]] > 0) return edges[i];
        // }

        // return {};