// Jan. 7th, 2025 (daily)

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;

        for (int i = 0; i < words.size(); ++i) {
            string& curr = words[i];
            for (int j = i+1; j < words.size(); ++j) {
                if (words[j].find(curr) == 0 && words[j].rfind(curr)+curr.size() == words[j].size()) cnt++;
            }
        }

        return cnt;
    }
};