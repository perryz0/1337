// June 21st, 2025 (daily)

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int it=0;
        int n=s.length();
        vector<string> ans;
        while (it<n) {
            string group;
            for (int j=0; j<k && it<n; ++j) {
                group += s[it];
                it++;
            }
            ans.push_back(group);
        }

        while (ans[ans.size()-1].length() < k) {
            ans[ans.size()-1].push_back(fill);
        }

        return ans;
    }
};