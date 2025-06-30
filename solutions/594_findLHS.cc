// June 29th, 2025 (daily)

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;  // num->freq
        for (const int& n : nums) freq[n]++;

        int ans=0;
        for (auto [n,f] : freq) {
            if (!freq.contains(n-1)) continue;
            // if (f && freq[n-1]){
                // cout << "satisfied num: " << n << ", freq: " << f << endl; 
            ans=max(ans, f+freq[n-1]);
            // } 
        }

        return ans;
    }
};