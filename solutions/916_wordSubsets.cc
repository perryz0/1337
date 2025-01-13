// Jan. 9th, 2025 (daily)

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        unordered_map<char, int> freqs;

        vector<int> v_freqs(26, 0);
        for (string& word : words2) {
            for (int i = 0; i < word.length(); ++i) {
                char c = word[i];
                v_freqs[c-'a']++;
                freqs[c] = max(v_freqs[c-'a'], freqs[c]);
            }
            fill(v_freqs.begin(), v_freqs.end(), 0);
        }

        for (string& word : words1) {
            res.push_back(word);
            for (int i = 0; i < word.length(); ++i) {
                char c = word[i];
                v_freqs[c-'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                if (freqs[j+'a'] > v_freqs[j]) {
                    res.pop_back();
                    break;
                }
            }
            fill(v_freqs.begin(), v_freqs.end(), 0);
        }

        return res;
    }
};