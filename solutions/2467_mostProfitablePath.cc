// Feb. 23rd, 2025 (daily)

class Solution {
    private:
        int treeDepth = 0;
        unordered_set<int> visited;
        bool isPath = false;
    
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    
            int n = edges.size()+1;
            vector<vector<int>> adj(n);
            for (auto& e : edges) {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
    
            // precalculate bob dfs to 0
            bobDfs(bob, 0, adj, 0, amount);
            visited.clear();
    
            // now alice just dfs and maximize the greatest result
            int res = INT_MIN;
            dfs(0, adj, res, 0, amount);
    
            return res;
        }
    
        void dfs(int curr, const vector<vector<int>>& adj, int& res, int acc, const vector<int>& amount) {
            visited.insert(curr);
            acc += amount[curr];
    
            bool isLeaf = true;
            for (int next : adj[curr]) {
                if (visited.count(next)) continue;
                isLeaf = false;
                dfs(next, adj, res, acc, amount);
            }
    
            if (isLeaf) res = max(res, acc);
        }
    
        void bobDfs(int curr, const int& dst, const vector<vector<int>>& adj, int depth, vector<int>& amount) {
            depth++;
            visited.insert(curr);
    
            if (curr == dst) { isPath = true; treeDepth = depth; return; }
    
            // traverse towards the parent
            for (int next : adj[curr]) {
                if (visited.count(next)) continue;
                bobDfs(next, dst, adj, depth, amount);
                if (isPath) break;
            }
    
            // backtrack now to update the bob-affected gates
            if (depth <= (treeDepth+1)/2 && isPath) {
                // c/2 case
                if (depth == (treeDepth+1)/2 && treeDepth%2 == 1) amount[curr] = amount[curr]/2;
                else {
                    amount[curr] = 0;
                }
            } 
        }
    };
    
            // reconstruct tree
            // alice dfs to a leaf, bob only has a single path upwards (how trees work)
            // (root itself is depth=1)
            // case 1: bob is at an even depth, alice and bob will never "meet"
            // case 2: bob is at an odd depth, alice and bob can possibly "meet", see if this optimizes alice leaf net result
            // as for the dfs travesal, alice cares about:
            // 1. which node she meets bob (singular bob path, precalculate this), and bob's path
            // 2. then calculate the c/2 specifically for this node
            // 3. for the other bob paths, just set the val to 0