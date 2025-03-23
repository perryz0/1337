// Mar. 22nd, 2025 (daily)

#define ll long long
#define MOD 1000000007

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // count total number of dijkstras
        
        // use adj matrix
        vector<vector<int>> adj(n, vector<int>(n, 0));

        for (auto& road : roads) {
            adj[road[0]][road[1]] = road[2];
            adj[road[1]][road[0]] = road[2];
        }

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> minpq;
        minpq.push({0,0});  // {cost, node}

        vector<ll> costs(n, LLONG_MAX);
        costs[0]=0;
        vector<int> pcnts(n, 0);
        pcnts[0]=1;

        while (!minpq.empty()) {
            auto [c, v] = minpq.top();
            minpq.pop();

            for (int i = 1; i<n; ++i) {
                if (adj[v][i] == 0) continue;

                ll newCost = c + adj[v][i];
                if (newCost < costs[i]) {
                    costs[i] = newCost;
                    pcnts[i] = pcnts[v];
                    minpq.push({costs[i], i});
                }
                else if (newCost == costs[i]) {
                    pcnts[i] = (pcnts[i] + pcnts[v])%MOD;  
                }
            }
        }


        return pcnts[n-1];
    }
};