// May 14th, 2025 (daily)

class Solution {
private:
    int dp[1000];
    int prev[1000];

    int ham(string& a, string& b) {
        int diff = 0;
        for (int i=0; i<a.length(); ++i) {
            diff += (a[i] != b[i]);
        }

        return diff;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> res;
        memset(dp, 0, sizeof(dp));
        memset(prev, -1, sizeof(prev));

        int maxLen=0, maxIdx=0;

        for (int i=0; i<n; ++i) {
            dp[i] = 1;  // each word alone is valid subsequence
            for (int j=0; j<i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    ham(words[i], words[j]) == 1) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        // reconstruct res with prev
        vector<string> path;
        while (maxIdx != -1) {
            path.push_back(words[maxIdx]);
            maxIdx = prev[maxIdx];
        }

        // traced backwards so rev
        reverse(path.begin(), path.end());
        return path;
    }
};