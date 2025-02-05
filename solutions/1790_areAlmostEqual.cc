// Feb. 4th, 2025 (daily)

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        vector<int> freqs1(26, 0);
        vector<int> freqs2(26, 0);
        for (int i = 0; i < s1.length(); ++i) {
            freqs1[s1[i]-'a']++;
            freqs2[s2[i]-'a']++;
            if (s1[i] != s2[i]) cnt++;
        }

        for (int i = 0; i < 26; ++i) if (freqs1[i] != freqs2[i]) return false;

        return (cnt > 2) ? false : true;
    }
};