// Mar. 21st, 2025 (daily)

class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            // count components
            // out of those, count the ones that are complete
    
            unordered_set<int> vis;
            vector<vector<int>> comps;
            int cnt = 0;
    
            vector<vector<int>> adj(n);
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
    
            for (int i = 0; i<n; ++i) {
                if (vis.find(i) == vis.end()) {
                    vector<int> comp;
                    dfs(i, vis, comp, adj);
                    comps.push_back(comp);
                }
            }
    
            // stupid method
            // then bfs from random vertex in every component
            // for (auto& comp : comps) {
            //     cnt += bfs(comp[0], comp, adj);
            // }
    
            // individual counts
            // for (auto& comp : comps) {
            //     int sz = comp.size();
            //     int edges = 0;
            //     for (int i = 0; i<sz; ++i) {
            //         if (adj[comp[i]].size() != sz-1) break;
            //         edges++;
            //     }
            //     // cout << edges << endl;
            //     if (edges == sz) cnt++;
            // }
    
            // even better v*(v-1)/2
            for (auto& comp : comps) {
                int v = comp.size();
                int e = 0;
                for (int& vertex : comp) {
                    e += adj[vertex].size();
                }
    
                // undirected overcount
                if (e/2 == v*(v-1)/2) cnt++;
            }
    
            return cnt;
        }
    
        void dfs(int curr, unordered_set<int>& vis, vector<int>& comp, const vector<vector<int>>& adj) {
            comp.push_back(curr);
            vis.insert(curr);
    
            for (const int& dst : adj[curr]) {
                if (vis.find(dst) == vis.end()) {
                    dfs(dst, vis, comp, adj);
                }
            }
        }
    
        bool bfs(int curr, vector<int>& comp, const vector<vector<int>>& adj) {
            queue<int> q;
            unordered_set<int> v;
            for (const int& dst : adj[curr]) {
                q.push(dst);
            }
    
            if (q.size() < comp.size()-1) return false;
    
            while (!q.empty()) {
                int c = q.front();
                q.pop();
                v.insert(c);
    
                int cnt = 0;
                for (const int& dst : adj[curr]) {
                    q.push(dst);
                    cnt++;
                }
    
                if (cnt < comp.size()-1) return false;
            }
    
            return true;
        }
    };