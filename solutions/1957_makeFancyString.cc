// July 20th, 2025

class Solution {
public:
    string makeFancyString(string s) {
        string ans = s.substr(0,2);
        int n=s.length();
        for (int i=2; i<n; ++i) {
            if (ans[ans.length()-1] == s[i] && ans[ans.length()-2] == s[i]) continue;
            ans.push_back(s[i]);
        }

        return ans;
    }
};