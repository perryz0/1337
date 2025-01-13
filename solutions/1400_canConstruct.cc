// Jan. 10th, 2025 (daily)

class Solution {
public:
    bool canConstruct(string s, int k) {

        if (s.length() < k) return false;

        vector<int> freqs(26);
        for (char& c : s) freqs[c-'a']++;

        int oddCnt = 0;
        for (int i = 0; i < freqs.size(); ++i) if (freqs[i] % 2 == 1) oddCnt++;

        return (oddCnt <= k) ? 1 : 0;
    }
};