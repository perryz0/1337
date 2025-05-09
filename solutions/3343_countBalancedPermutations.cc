// May 8th, 2025 (daily)

#define MOD 1000000007

class Solution {
public:
    using ll = long long;

    int countBalancedPermutations(string num) {
        int N = num.size();
        vector<int> f(10, 0);
        for (char c : num) f[c - '0']++;

        // total digit sum
        int total_sum = 0;
        for (int d = 0; d < 10; ++d) {
            total_sum += d * f[d];
        }

        if (total_sum % 2 != 0) return 0;
        int target = total_sum / 2;
        int max_odd = (N + 1) / 2;

        // precompute factorials and inv factorials
        vector<ll> fact(N + 1, 1), ifact(N + 1, 1);
        for (int i = 1; i <= N; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        ifact[N] = modinv(fact[N]);
        for (int i = N - 1; i >= 1; --i)
            ifact[i] = ifact[i + 1] * (i + 1) % MOD;

        // comb[i][j] = C(i, j)
        vector<vector<ll>> comb(max_odd + 1, vector<ll>(max_odd + 1, 0));
        for (int i = 0; i <= max_odd; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // dp[sum][odd_count] = num ways to reach sum with odd_count digits in odd positions
        vector<vector<ll>> dp(target + 1, vector<ll>(max_odd + 1, 0));
        dp[0][0] = 1;

        int digits_used = 0, sum_used = 0;
        for (int d = 0; d < 10; ++d) {
            int cnt = f[d];
            if (cnt == 0) continue;

            digits_used += cnt;
            sum_used += d * cnt;

            for (int odd = min(digits_used, max_odd); odd >= max(0, digits_used - (N - max_odd)); --odd) {
                int even = digits_used - odd;

                for (int s = min(sum_used, target); s >= max(0, sum_used - target); --s) {
                    ll new_val = 0;
                    for (int j = max(0, cnt - even); j <= min(cnt, odd) && d * j <= s; ++j) {
                        int odd_take = j;
                        int even_take = cnt - j;
                        ll ways = comb[odd][odd_take] * comb[even][even_take] % MOD;
                        new_val = (new_val + ways * dp[s - d * odd_take][odd - odd_take] % MOD) % MOD;
                    }
                    dp[s][odd] = new_val;
                }
            }
        }

        return dp[target][max_odd];
    }

private:
    // using ll = long long;

    ll modinv(ll x) {
        return modpow(x, MOD - 2);
    }

    ll modpow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }
};
