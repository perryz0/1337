class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0;  // convergence threshold

        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;

        function<double(int, int)> dfs = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0) return 1.0;
            if (b <= 0) return 0.0;
            if (dp[a].count(b)) return dp[a][b];
            return dp[a][b] = 0.25 * (
                dfs(a - 4, b) +
                dfs(a - 3, b - 1) +
                dfs(a - 2, b - 2) +
                dfs(a - 1, b - 3)
            );
        };

        return dfs(m, m);
    }
};

// hardcoding way too much with the strict layer-based sim

// class Solution {
// public:
//     struct pair_hash {
//         size_t operator()(const pair<int, int>& p) const {
//             return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
//         }
//     };

//     double soupServings(int n) {
//         if (n==0) return 0.5;   // A and B end at the same time 100%, technically 0.50.
//         if (n<=25) return 0.625;

//         // normalize N to multiples of the drain
//         n = ceil((double)n/25.0);

//         // now we have -1,-2,-3,-4

//         // imbalanced ops, no 0ml poured from A and 100ml from B
//         // thus by the LOE, the ans converges to 1 pretty fast.
//         // i.e. E[A] = 0.25(100+75+50+25)= 62.5
//         // i.e. E[B] = 0.25(0+75+50+25)= 37.5
//         // so E[drain diff] = 25
//         if (n > 200) return 1.0;    // ans converges to 1.0, according to editorial lol

//         // now simulate
//         double ans = 0;
//         using ProbMap = unordered_map<pair<int, int>, double, pair_hash>;
//         vector<ProbMap> dp(n/2 + 1);  // deepest search stack would be the 50ml-50ml before either one drains
//         dp[0][{n,n}] = 1.0;          // start with full prob mass at (n, n)
//         vector<pair<int,int>> ops = {{-4,0},{-3,-1},{-2,-2},{-1,-3}};

//         for (int i = 1; i <= n/2; ++i) {
//             for (const auto& [prevState, prevProb] : dp[i-1]) {
//                 int prevA = prevState.first, prevB = prevState.second;
//                 if (prevA <= 0 || prevB <= 0) continue;   // should be the end of the search for this process
//                 for (const auto& [dA, dB] : ops) {
//                     int newA = prevA+dA, newB = prevB+dB;
//                     double p = prevProb * 0.25;
//                     if (newA <= 0 && newB <= 0) ans += p*0.5;
//                     else if (newA <= 0) ans += p;
//                     else if (newB <= 0) continue;
//                     else dp[i][{newA, newB}] += p; // push with probability mass
//                 }
//             }
//         }

//         return ans;
//     }
// };


//         // probabilities
//         // double ans=0;
//         // double currProb=0.25;
//         // for (int i=1; i<n/2+1; ++i) {
//         //     for (const auto& [A, B] : dp[i]) {
//         //         // cout << "A vol is: " << A << ", B vol is: " << B << endl;
//         //         if (A <= 0 && B <= 0) ans += currProb*0.5;
//         //         else if (A <= 0) ans += currProb;
//         //     }
//         //     currProb *= 0.25;
//         // }

// //         return ans;
// //     }
// // };