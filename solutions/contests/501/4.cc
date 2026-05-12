using pll = pair<long long, long long>;

class Solution {
private:
    vector<int> ans;
    vector<vector<long long>> empty, carry;
    vector<vector<pair<long long,long long>>> emptyAdj, carryAdj;
    int N,M;

    // empty[i] = distTo for all the shops to shop i
    vector<long long> dijk(int src, const vector<vector<pair<long long,long long>>>& adj){
        vector<long long> dist(N, LLONG_MAX);// init with inf

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        dist[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            auto [curDist, u] =pq.top();pq.pop();

            if(curDist != dist[u]) continue;

            for(auto [v,w] : adj[u]){
                if(dist[v]> curDist+w){
                    dist[v]=curDist+w;
                    pq.push({dist[v],v});
                }
            }
        }

        return dist;
    }
    
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        //n vertices, m roads
        N=n;
        M=roads.size();

        empty.resize(n); carry.resize(n);
        emptyAdj.resize(n); carryAdj.resize(n);

        // ------> empty handed, pay sum(cost[i]) at each stop to j-th stop
        // get the apple (+prices[j])
        // <----- return trip, pay sum(cost[k]*tax), these nodes can be different. bc tax is diff

        // finding the shortest path from each node to every other node
        // multisource shortest path, keep minimizing
        // can use dijkstras, dont need FW

        // init the upper bound first (worst we can do at each local shop)
        ans=prices;
        // build the graph
        // NEED 2 adjs: one for empty, one for carry
        for(const auto& r : roads){
            int u=r[0],v=r[1],c=r[2],t=r[3];

            emptyAdj[u].push_back({v,c});
            emptyAdj[v].push_back({u,c});

            carryAdj[u].push_back({v,1LL*c*t});
            carryAdj[v].push_back({u,1LL*c*t});
        }

        // run all dijkstras needed
        for(int i=0; i<n; ++i){
            empty[i]=dijk(i, emptyAdj);
            carry[i]=dijk(i, carryAdj);
        }

        // query answer structure:
        for(int i=0; i<n; ++i){
            for(int shop=0; shop<n; ++shop){
                // not reachable cases
                if(empty[i][shop]==LLONG_MAX || carry[shop][i]==LLONG_MAX) continue;
                ans[i]=min(1LL*ans[i], empty[i][shop] + prices[shop] + carry[shop][i]);
            }
        }
        
        return ans;
    }
};