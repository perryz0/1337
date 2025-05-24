// May 23rd, 2025 (daily)

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;

        for (int i=0; i<words.size(); ++i) {
            if (words[i].find(x) != string::npos) res.push_back(i);
        }

        return res;
    }
};