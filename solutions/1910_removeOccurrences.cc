// Feb. 10th, 2025 (daily)

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while (s.length() > 0 && s.length() > s.find(part)) s.erase(s.find(part), part.length());
            return s;
        }
    };
    
    
        // string removeOccurrences(string s, string part) {
        //     int n = s.length(), m = part.length();
        //     if (m > n) return s;
    
        //     stack<char> stk;
        //     string match;
    
        //     for (int i = 0; i < n; ++i) {
        //         stk.push(s[i]);
        //         if (stk.top() == part[m-1] && stk.size() >= m) {
        //             match = "";
        //             for (int j = 0; j < m; ++j) {
        //                 match = stk.top() + match;
        //                 stk.pop();
        //             }
        //             if (match != part) for (char& c: match) stk.push(c);
        //         }
        //     }
    
        //     string res(stk.size(), ' ');
        //     for (int i = stk.size() - 1; i >= 0; i--) {
        //         res[i] = stk.top();
        //         stk.pop();
        //     }
    
        //     return res;
        // }