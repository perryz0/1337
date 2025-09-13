// Sep. 12th, 2025

class Solution {
public:
    int maxFreqSum(string s) {
        string vow="aeiou";
        vector<int> v(26,0), c(26,0);
        for (const char& ch : s) {
            int slot = ch-'a';
            if (vow.find(ch) == string::npos) v[slot]++;
            else c[slot]++;
        }

        int MAXV=0, MAXC=0;
        for (const int& slot : v) MAXV=max(MAXV,slot);
        for (const int& slot : c) MAXC=max(MAXC,slot);

        return MAXV+MAXC;
    }
};