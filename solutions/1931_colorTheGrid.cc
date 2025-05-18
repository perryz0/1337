#define MOD 1000000007

class Solution {
public:
    int colorTheGrid(int m, int n) {
        int N = pow(3, m);
        vector<vector<int>> pat(N);   // pat[i]: color pattern of mask i
        vector<int> mask;             // valid masks

        // find valid col patterns
        for (int i = 0; i < N; ++i) {
            int x = i;
            bool ok = true;
            vector<int> col(m);
            for (int j=0; j<m; ++j) {
                col[j] = x % 3;
                x /= 3;
                if (j > 0 && col[j] == col[j-1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                mask.push_back(i);
                pat[i] = col;
            }
        }

        int M = mask.size();
        vector<vector<bool>> valid(M, vector<bool>(M));

        // valid transitions between col patterns
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                bool ok = true;
                for (int k = 0; k < m; ++k) {
                    if (pat[mask[i]][k] == pat[mask[j]][k]) {
                        ok = false;
                        break;
                    }
                }
                valid[i][j] = ok;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(M));
        for (int i = 0; i < M; ++i) dp[1][i] = 1;

        for (int c=2; c<=n; ++c) {
            for (int i=0; i<M; ++i) {
                for (int j=0; j<M; ++j) {
                    if (valid[i][j]) {
                        dp[c][i] = (dp[c][i] + dp[c-1][j]) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for (int i=0; i<M; ++i) ans = (ans + dp[n][i]) % MOD;
        return ans;
    }
};








// complementary counting fails because its markov
// #define ll long long
// #define lll __int128
// #define MOD 1000000007

// class Solution {
// // private:
//     // vector<vector<int>> dp;

// public:
//     int colorTheGrid(int m, int n) {
//         // int ans = 0;
//         vector<vector<ll>> dp(m, vector<ll>(n, 0));
//         // boundary cases always just prev*2
//         // other cases have 2 neighbors, complementary counting:
//         // 6 ways left, 6 ways above, 6*6 - (18)
//         dp[0][0] = 3;
//         ll inv2 = powmod(2, MOD-2, MOD);    // FLT
//         for (int i=0; i<m; ++i) {
//             for (int j=0; j<n; ++j) {
//                 if (dp[i][j] != 0) continue;
//                 if (i == 0) {
//                     dp[i][j] = (dp[i][j-1]*2)%MOD;
//                 }
//                 else if (j == 0) {
//                     dp[i][j] = (dp[i-1][j]*2)%MOD;
//                 }
//                 // non boundary case
//                 else {
//                     dp[i][j] = ((lll)dp[i][j-1] * dp[i-1][j] % MOD) * inv2 % MOD;
//                 }
//             }
//         }

//         // return ans;
//         return static_cast<int>(dp[m-1][n-1]);
//     }

//     ll powmod(ll base, ll exp, ll mod) {
//         ll result = 1;
//         base %= mod;
//         while (exp > 0) {
//             if (exp & 1)
//                 result = result * base % mod;
//             base = base * base % mod;
//             exp >>= 1;
//         }
//         return result;
//     }

// };