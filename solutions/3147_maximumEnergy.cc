// Oct. 9th, 2025

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        // dp problem, dp[i]=max energy to gain from idx i
        vector<int> dp(n, INT_MIN);
        for (int i=n-1; i>n-1-k; --i) dp[i]=energy[i];
        for (int i=n-1-k; i>=0; --i) dp[i]=energy[i]+dp[i+k];
        
        int ans=INT_MIN;
        for (const int& e : dp) ans=max(ans,e);

        return ans;
    }
};