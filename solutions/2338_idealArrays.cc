// Apr. 21st, 2025 (daily)
//refactored editorial...

#define MOD 1000000007
#define ll long long
#define MAX 10014

class Solution {
private:
    vector<ll> f, inv_f;
    vector<int> sieve;
    vector<vector<int>> prime_exponents;

    ll modpow(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void init_facs() {
        f.resize(MAX);
        inv_f.resize(MAX);
        f[0] = inv_f[0] = 1;
        for (int i = 1; i < MAX; ++i) {
            f[i] = f[i - 1] * i % MOD;
            inv_f[i] = modpow(f[i], MOD - 2);
        }
    }

    ll comb(int a, int b) {
        if (b > a || b < 0) return 0;
        return f[a] * inv_f[b] % MOD * inv_f[a - b] % MOD;
    }

    void init_sieve(int limit) {
        sieve.resize(limit + 1);
        prime_exponents.resize(limit + 1);
        for (int i = 2; i <= limit; ++i) {
            if (sieve[i] == 0) {
                for (int j = i; j <= limit; j += i) {
                    if (sieve[j] == 0) sieve[j] = i;
                }
            }
        }

        for (int i = 2; i <= limit; ++i) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                prime_exponents[i].push_back(cnt);
            }
        }
    }

public:
    int idealArrays(int n, int maxValue) {
        //stars and bars: C(n+p-1,p), where p = # prime exps
        //CANNOT SOLVE THIS SHIT LOL
        init_facs();
        init_sieve(maxValue);

        ll total = 0;

        for (int x = 1; x <= maxValue; ++x) {
            ll ways = 1;
            for (int e : prime_exponents[x]) {
                ways = ways * comb(n - 1 + e, e) % MOD;
            }
            total = (total + ways) % MOD;
        }

        return total;
    }
};
