// Oct. 12th, 2025

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string rep;
        for (const string& w : words) {
            string cur = w;
            sort(cur.begin(), cur.end());
            if (rep == cur) continue;
            rep = cur;
            ans.push_back(w);
        }
        return ans;
    }
};