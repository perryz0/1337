// May 1st, 2025 (daily)

class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.length();
            unordered_map<char,int> dirs;
            dirs['L'] = -1;
            dirs['R'] = 1;
    
            string res = dominoes;
            vector<int> time(n, -1);  // -1 means not yet affected
            vector<char> force(n, '.'); // track the first L or R that affected this specific .
    
            // 1d bfs
            queue<tuple<int,char,int>> q; // (index, dir, time)
            for (int i=0; i<n; ++i) {
                if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                    q.push({i, dominoes[i], 0});
                    time[i] = 0;
                    force[i] = dominoes[i];
                }
            }
    
            while (!q.empty()) {
                auto [curr, dir, t] = q.front();
                q.pop();
    
                int toChange = curr + dirs[dir];
                if (toChange < 0 || toChange >= n) continue;
                if (res[toChange] != '.') continue;
    
                if (time[toChange] == -1) {
                    force[toChange] = dir;
                    time[toChange] = t+1;
                    q.push({toChange, dir, t+1});
                } else if (time[toChange] == t+1 && force[toChange] != dir) {
                    force[toChange] = '.';
                }
            }
    
            for (int i=0; i < n; ++i) if (res[i] == '.') res[i] = force[i];
    
            return res;
        }
    };
    
    
    
    
    
    
    
    
    
    
    
    
    
                // need to track 'time', the window of opportunity to still change the toChange idx to R or L, after that it means its a sandwiched '.'
                // if (res[curr] != '.') {
                //     int toChange = curr + dirs[res[curr]];
                //     if (res[toChange] == '.') {
                //         if (toChange == 0 || toChange == n-1) {
                //             res[toChange] = res[curr];
                //         }
                //         else {
                //             // if (!(toChange-1 >= 0 && res[toChange-1] == '.') || !(toChange+1 < n && res[toChange+1] == '.')) {
                //             //     continue;
                //             // }
                //             if ((toChange-1 >= 0 && res[toChange-1] == '.') || (toChange+1 < n && res[toChange+1] == '.')) {
                //                 res[toChange] = res[curr];
                //                 q.push(toChange);
                //             }
                //         }
                //     }
                // }