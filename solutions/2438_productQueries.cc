// Aug 10th, 2025

constexpr int MOD = 1e9+7;
using ll = long long;

class Solution {
private:
    vector<ll> powers;

    ll modPow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    void precompute() {
        for (int i=0; i<32; ++i) {
            powers[i] = 1LL << i;
        }
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        powers = vector<ll>(32, 0);
        precompute();
        // for (const ll& pow : powers) cout << pow << " ";
        // cout << endl;
        long sum=n;
        int iter = powers.size()-1;
        vector<int> p;
        while (sum>0) {
            if (powers[iter] > sum) {
                iter--;
                continue;
            }
            sum -= powers[iter];
            p.push_back(powers[iter]);
            iter--;
        }

        sort(p.begin(), p.end());

        vector<ll> prefixPROD(p.size(), 0);
        prefixPROD[0] = p[0]%MOD;
        for (int i=1; i<p.size(); ++i) prefixPROD[i]=(prefixPROD[i-1]*p[i]) % MOD;

        vector<int> ans;
        for (const auto& q : queries) {
            int left = q[0], right = q[1];
            ll prod = (left == 0) ? prefixPROD[right] : (prefixPROD[right] * modPow(prefixPROD[left-1], MOD-2)) % MOD;
            ans.push_back(prod);
        }

        return ans;
    }
};