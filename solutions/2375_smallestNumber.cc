// Feb. 17th, 2025 (daily)

class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.length();
            // string num(n+1, ' ');
            string num;
            // unordered_set<char> digits = {'1','2','3','4','5','6','7','8','9'};
    
            stack<char> stk;
            int curr = 1;
            for (int i = 0; i<n; ++i) {
                stk.push(curr+'0');
                curr++;
                // if (i == n) stk.push
                if (pattern[i] == 'I') {
                    while (!stk.empty()) {
                        num.push_back(stk.top());
                        stk.pop();
                    }
                }
            }
    
            stk.push(curr+'0');     // one more push
            while (!stk.empty()) {
                num.push_back(stk.top());
                stk.pop();
            }
    
            return num;
        }
    };