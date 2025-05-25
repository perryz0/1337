// May 24th, 2025 (daily)

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freqs;
        int res = 0;
        for (const string& w : words) {
            string tmp = w;
            reverse(tmp.begin(), tmp.end());
            if (freqs[tmp] > 0) {
                freqs[tmp]--;
                res += 4;
            }
            else {
                freqs[w]++;
            }
        }

        // check if theres any hanging pairs
        for (int i=0; i<26; ++i) {
            string pair(2, static_cast<char>(i + 'a'));
            if (freqs[pair] > 0) {
                res += 2;
                break;
            }
        }

        return res;
    }
};