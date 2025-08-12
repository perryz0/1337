// Aug 11th, 2025

constexpr int MOD = 1e9+7;

class Solution {
private:
    vector<int> pows;
    int dp[301][301]; // dp[idx][curSum], -1 means not computed
    int N;

    int backtrack(int idx, int curSum) {
        if (curSum >= N) {
            return (curSum == N) ? 1 : 0;
        }

        if (dp[idx][curSum] != -1) return dp[idx][curSum];

        long long ways = 0;
        for (int i=idx+1; i<pows.size(); ++i) {
            ways += backtrack(i, curSum + pows[i]);
            if (ways >= MOD) ways %= MOD;
        }

        return dp[idx][curSum] = (int)ways;
    }

public:
    int numberOfWays(int n, int x) {
        // precompute pows
        pows.clear();
        for (int i=1; i<=n; ++i) {
            long long power = 1;
            for (int j=0; j<x; ++j) power *= i; // safer than pow()
            if (power > n) break;
            pows.push_back((int)power);
        }

        memset(dp,-1,sizeof(dp));
        N = n;

        long long ans = 0;
        for (int i=0; i<(int)pows.size(); ++i) {
            ans += backtrack(i, pows[i]);
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }
};



// constexpr int MOD = 1e9+7;

// class Solution {
// private:
//     vector<int> pows;
//     int dp[301];
//     int ans;
//     int N;

//     void backtrack(int idx, int curSum) {
//         if (curSum >= N) {
//             if (curSum == N) ++ans;
//             return;
//         }

//         for (int i=idx+1; i<pows.size(); ++i) {
//             curSum += pows[i];
//             backtrack(i, curSum);
//             curSum -= pows[i];
//         }
//     }

// public:
//     int numberOfWays(int n, int x) {
//         // precompute pows
//         memset(dp, 0, 301);
//         for (int i=1; i<=n; ++i) {
//             int power = pow(i,x);
//             if (power > n) break;
//             pows.push_back(power);
//         }

//         // for (const int& p : pows) cout << p << " ";
//         // cout << endl;

//         // choose or not choose backtrack
//         ans=0;
//         N=n;

//         for (int i=0; i<pows.size(); ++i) {
//             backtrack(i, pows[i]);
//         }

//         return ans;
//     }
// };