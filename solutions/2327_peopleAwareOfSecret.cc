// Sep. 8th, 2025

constexpr int MOD=1e9+7;

class Solution {
public:
    int peopleAwareOfSecret(int n,int delay,int forget){
        vector<long long> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=max(1,i-forget+1);j<=i-delay;j++){
                dp[i]=(dp[i]+dp[j])%MOD;
            }
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            if(i>=1)ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};

// constexpr int MOD =1e9+7;

// class Solution {
// public:
//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         // without forget:
//         // 1 -> 2 -> 4 -> 8

//         vector<long> dp(n+1, 1);
//         // dp[1]=1;
//         for (int i=1+delay; i<=n; ++i) {
//             // correct the prev dp first
//             if (i-forget >= 1) {
//                 dp[i-delay] -= dp[i-forget];
//             }
//             // dp[i]=(dp[i-delay]*2)%MOD;   // not just *2 because delay can be >1
//             dp[i]=(dp[i-delay]*2)%MOD;

//         }

//         return dp[n];
//     }
// };