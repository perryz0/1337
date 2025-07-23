// July 22nd, 2025

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // greedily remove the max(x,y) pattern
        string pattern;
        if (max(x,y) == x) pattern = "ab";
        else pattern = "ba";

        stack<char> stk;    // only tracking a's and b's
        int n=s.length();
        int ans=0;

        stack<char> trails;
        for (int i=0; i<n; ++i) {
            if (s[i] != 'a' && s[i] != 'b') {
                // handle the rev pattern
                while (!stk.empty()) {
                    char c = stk.top();
                    stk.pop();
                    if (c == pattern[1]) {
                        if (trails.empty()) continue;
                        else {
                            trails.pop();
                            ans += min(x,y);
                            // cout << "smaller pattern matched, idx: " << i << endl;
                        }
                    }
                    else {
                        trails.push(c);
                    }
                }
                while (!trails.empty()) trails.pop();
                continue;
            }
            if (!stk.empty() && stk.top() == pattern[0] && s[i] == pattern[1]) {
                ans += max(x,y);
                stk.pop();
                // cout << "bigger pattern matched, idx: " << i << endl;
                continue;
            }
            // otherwise push the current a/b
            stk.push(s[i]);
        }

        // handle rev one more time
        while (!stk.empty()) {
            char c = stk.top();
            stk.pop();
            if (c == pattern[1]) {
                if (trails.empty()) continue;
                else {
                    trails.pop();
                    ans += min(x,y);
                    // cout << "smaller pattern matched at EOL" << endl;
                }
            }
            else {
                trails.push(c);
            }
        }

        return ans;
    }
};