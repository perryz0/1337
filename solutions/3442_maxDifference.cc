// June 9th, 2025 (daily)

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freqs(26,0);

        for (const char& c : s) freqs[c-'a']++;

        int odd=0, even=INT_MAX;
        for (int i=0; i<26; ++i) {
            if (freqs[i]==0) continue;
            if (freqs[i]%2) odd=max(odd,freqs[i]);
            else even=min(even,freqs[i]);
        }

        return odd-even;
    }
};