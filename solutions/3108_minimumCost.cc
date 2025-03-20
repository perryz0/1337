// Mar. 19th, 2025 (daily)

class UF {
    private:
        vector<int> parent;
        vector<int> size;
    
    public:
        explicit UF(int n) : parent(n), size(n, 1) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;  // each node is its own parent (init)
            }
        }
    
        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
    
        void UNION(int x, int y) {
            x = find(x);
            y = find(y);
            if (x!=y) {
                if (size[x] < size[y]) {
                    parent[x] = y;
                    size[y] += size[x];
                } else {
                    parent[y] = x;
                    size[x] += size[y];
                }
            }
        }
    };
    
    class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    
            // UF
            UF uf(n);
            for (auto& edge : edges) {
                uf.UNION(edge[0],edge[1]);
            }
    
            unordered_map<int,int> compCosts;
            for (auto& edge : edges) {
                int r = uf.find(edge[0]);
                if (compCosts.find(r) == compCosts.end()) {
                    compCosts[r] = edge[2];
                }
                else {
                    compCosts[r] &= edge[2];
                }
            }
    
            // ans each query
            int q = query.size();
            vector<int> res(q);
            int it = 0;
            for (auto& q : query) {
                int r1 = uf.find(q[0]), r2 = uf.find(q[1]);
                if (r1 != r2) res[it] = -1;
                else res[it] = compCosts[r1];
                it++;
            }
    
            return res;
        }
    };
    