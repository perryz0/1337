// May 3rd, 2025 (daily)

class Solution {
    private:
        struct pair_hash {
            size_t operator()(const pair<int,int>& p) const {
                return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
            }
        };
    
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            // unordered_set<pair<int,int>> s;
            // unordered_map<int,vector<int>> mp;      // <a: b candidates>
    
            unordered_map<pair<int,int>,int,pair_hash> eqpairs;
            for (auto& d : dominoes) {
                eqpairs[{min(d[0],d[1]), max(d[0],d[1])}]++;
            }
    
            int res = 0;
            for (auto& [p, cnt] : eqpairs) {
                // cout << "pair is: " << p.first << "," << p.second << "; cnt is: " << cnt << endl;
                res += (cnt * (cnt-1))/2;
            }
    
            return res;
        }
    };
    
    
    
    
    
    
    
    
    
    
                // cout << v[0] << "," << v[1] << endl;
                // if (mp.find(v[0]) != mp.end()) {
                //     for (int i=0; i<mp[v[0]].size(); ++i) {
                //         if (mp[v[0]][i] == v[1]) {
                //             eqpairs[{v[0],v[1]}] += (eqpairs[{v[0],v[1]}] == 0) ? 2 : 1;
                //             cout << "curr cnt is: " << eqpairs[{v[0],v[1]}] << endl;
                //             break;
                //         }
                //     }
                // }
                // else if (mp.find(v[1]) != mp.end()) {
                //     for (int i=0; i<mp[v[1]].size(); ++i) {
                //         if (mp[v[1]][i] == v[0]) {
                //             eqpairs[{v[1],v[0]}] += (eqpairs[{v[1],v[0]}] == 0) ? 2 : 1;
                //             cout << "curr cnt is: " << eqpairs[{v[1],v[0]}] << endl;
                //             break;
                //         }
                //     }
                // } else {
                //     mp[v[0]].push_back(v[1]);
                // }