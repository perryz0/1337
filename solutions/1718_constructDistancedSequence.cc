// Feb. 15th, 2025 (daily)

class Solution {
    public:
        vector<int> constructDistancedSequence(int n) {
            // size = 2(n-1)+1 = 2n-2+1 = 2n-1
            // [n, n-2, n-4, (n-6) > 0, n-1, n-6,]
            // if asjgahdsogijasjd, idk lol
            vector<int> res(2*n-1, 0);
            // queue<vector<int>> candidates;
            vector<bool> used(n+1, false);
            used[n] = true; used[0] = true;
    
            // knowns
            res[0] = n;
            if (n>1) res[n] = n;
    
            if (n>1) construct(res, used, 1, n);
    
            return res;
        }
    
        bool construct(vector<int>& res, vector<bool>& used, int idx, const int& n) {
    
            if (idx == res.size()) return true;
    
            if (res[idx] != 0) return construct(res, used, idx+1, n);
    
            for (int j = n-1; j > 0; --j) {
    
                if (used[j]) continue;
    
                int next = (j==1) ? idx : idx+j;
                if (next >= res.size() || res[next] != 0) continue;
    
                res[idx] = j;
                if (j>1) res[next] = j;
                used[j] = true;
    
                if (construct(res, used, idx + 1, n)) return true;
    
                // undo placement if the backtrack failed
                res[idx] = 0;
                if (j>1) res[next] = 0;
                used[j] = false;
    
            }
    
            return false;
        }
    };
    
    
    
    
            // candidates.push(res);
            // queue<vector<int>> temp;
    
            // // greedy, constructions for largest per slot, return early when found a valid res
            // for (int i = 1; i < res.size(); ++i) {
            //     temp = queue<vector<int>>();
            //     while (!candidates.empty()) {
            //         vector<int> cand = candidates.front();
            //         candidates.pop();
            //         // if (cand[i] != 0) continue;
            //         if (construct(i, n, res, temp)) return temp.front();
            //     }
            //     candidates = temp;
            // }
    
            // cout << candidates.size() << endl;
    
            // return candidates.front();