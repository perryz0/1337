// May 31st, 2025 (daily)

using ll = long long;

class Solution {
private:
    ll nCr(ll n, ll r) {
        if (r>n-r) r = n-r; // symmetry
        ll res = 1;
        for (int i=1; i<=r; ++i) {
            res *= (n-r+i);
            res /= i;
        }
        return res;
    }

public:
    long long distributeCandies(int n, int limit) {

        // {n+2 choose 2} - loop({n-k+1 choose 1}), where n>=k>limit, nvm
        ll ans=nCr(n+2, 2);
        for (int mask = 1; mask < 8; ++mask) {
            int bits = 0;
            for (int i = 0; i<3; ++i)
                if (mask & (1 << i)) ++bits;

            ll excess = (ll)(limit+1) * bits;   // total excess candies
            if (n-excess < 0) continue;         // not enough candies left
            ll sub = nCr(n - excess + 2, 2);      // ways of remaining candies
            if (bits % 2 == 1) ans -= sub;
            else ans += sub;
        }

        return ans;
    }
};