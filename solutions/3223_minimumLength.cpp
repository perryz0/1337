// Jan. 12th, 2025 (daily)

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freqs(26, 0);

        for (int i = 0; i < s.length(); ++i) freqs[s[i]-'a']++;
        
        int ops = 0;
        for (int i = 0; i < 26; ++i) if (freqs[i] >= 3) ops += (((freqs[i]+1)/2)-1);

        return s.length()-ops*2;
    }
};