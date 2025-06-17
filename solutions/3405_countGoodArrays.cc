// June 17th, 2025 (daily)

#define MOD 1000000007
#define MAX 100000

using ll = long long;
// static bool c=false;

class Solution {
private:
    ll fact[MAX];
    ll invFact[MAX];

    ll nCr (int n, int r) {
        return fact[n] * invFact[r]%MOD * invFact[n-r]%MOD;
    }

    // compute all the factorials needed
    void compute() {
        if (fact[0]) return;    // already computed.
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < MAX; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[MAX - 1] = modPow(fact[MAX - 1], MOD - 2);  // single Fermat inv
        for (int i = MAX - 1; i > 0; --i) {
            invFact[i - 1] = (invFact[i] * i) % MOD;
        }
    }

    ll modPow(ll a, ll b) {
        ll res=1;
        a%=MOD;
        while (b>0) {
            if (b%2) res = res*a%MOD;
            a = a*a%MOD;
            b /= 2;
        }

        return res;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        // literally combinatorics
        // if (!c) {
        compute();
            // c=true;
        // }
        return nCr(n-1,k)*m%MOD * modPow(m-1, n-k-1)%MOD;
    }
};