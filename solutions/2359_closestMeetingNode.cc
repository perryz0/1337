// May 29th, 2025 (daily)

class Solution {
private:
    vector<int> d1;
    vector<int> d2; // min dists from n1 and n2
    vector<int> adj;

    void dfs(int u, int d, vector<int>& dist) {
        // cout << u << " " << adj[u] << endl;
        if (dist[u] != -1) return;  // cycle found
        dist[u] = d;
        if (adj[u] == -1) return;
        // if (dist[u] == tmp) return;
        dfs(adj[u], ++d, dist);
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        adj = edges;
        d1.assign(n, -1);   // -1 = unreachable
        d2.assign(n, -1);
        // d1[node1] = 0, d2[node2] = 0;

        // 1 dfs from node1 to every other node
        dfs(node1, 0, d1);

        // 1 dfs from node2 to every other node
        dfs(node2, 0, d2);

        int minOfMax = INT_MAX;
        int res = -1;
        for (int i=0; i<n; ++i) {
            if (d1[i] == -1 || d2[i] == -1) continue;   // node must be reachable by BOTH to be considered.
            if (max(d1[i], d2[i]) < minOfMax) {
                minOfMax = max(d1[i], d2[i]);
                res = i;
            }
            // minOfMax = min(minOfMax, max(d1[i], d2[i]));
        }

        // for (int i=0; i<n; ++i) cout << "node " << i << " has dist: " << d1[i] << " (from node1)" << endl;
        // cout << "-----------------------" << endl;
        // for (int i=0; i<n; ++i) cout << "node " << i << " has dist: " << d2[i] << " (from node2)" << endl;


        return res;    // only possible case for -1 retval is when node1, node2 in separate comps
    }
};