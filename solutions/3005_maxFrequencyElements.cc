// Sep. 21st, 2025

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101];
        memset(freq, 0, 101);
        for (const int& n : nums) freq[n]++;
        int MAX=0;
        for (const int& f : freq) MAX=max(MAX,f);
        int ans=0;
        for (const int& f : freq) if (MAX==f) ans += f;

        return ans;
    }
};