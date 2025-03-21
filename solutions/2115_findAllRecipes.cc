// Mar. 20th, 2025 (daily)

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
            // too lazy to optimize bruh, no caching :)
            int n = recipes.size();
            unordered_set<string> s;
            for (string& supply : supplies) s.insert(supply);
    
            vector<int> indeg(n);
    
            // create topo
            for (int i = 0; i<n; ++i) {
                int prereq = 0;
                for (int k = 0; k<ingredients[i].size(); ++k) {
                    if (s.find(ingredients[i][k]) == s.end()) prereq++;
                }
                indeg[i] = prereq;
            }
    
            vector<string> res;
            queue<int> q;   // contains i-th recipe
            for (int i = 0; i<n; ++i) {
                if (indeg[i] == 0) {
                    res.push_back(recipes[i]);
                    q.push(i);
                }
            }
    
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int i = 0; i<n; ++i) {
                    for (int k = 0; k<ingredients[i].size(); ++k) {
                        if (ingredients[i][k] == recipes[curr]){
                            indeg[i]--;
                            if (indeg[i] == 0) {
                                res.push_back(recipes[i]);
                                q.push(i);
                            }
                        }
                    }
                }
            }
    
            return res;
        }
    };
    
    
    
            // bad approach oops, the nesting could be bad
            // unordered_set<string> s;
            // unordered_set<string> res_set;
    
            // for (string& supply : supplies) s.insert(supply);
    
            // // two pass
            // for (int i = 0; i<n; ++i) {
            //     for (int k = 0; k<ingredients[i].size(); ++k) {
            //         if (k==ingredients[i].size()-1 && s.find(ingredients[i][k]) != s.end()) {
            //             s.insert(recipes[i]);
            //             res_set.insert(recipes[i]);
            //         }
            //         if (s.find(ingredients[i][k]) == s.end()) break;
            //     }
            // }
    
            // vector<string> res;
    
            // for (const string& r : res_set) res.push_back(r);
    
            // return res;