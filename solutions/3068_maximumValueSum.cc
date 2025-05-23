// May 23rd, 2025 (daily)

#define ll long long

class Solution {
private:
    vector<ll> a;
    int k, n;
    vector<vector<ll>> dp;

    ll dfs(int i, int parity) {
        if (i == n) return parity ? 0 : LLONG_MIN;
        if (dp[i][parity] != -1) return dp[i][parity];

        ll no = a[i] + dfs(i+1, parity);          // dont xor
        ll yes = (a[i] ^ k) + dfs(i+1, parity ^ 1); // do xor, flip

        return dp[i][parity] = max(no, yes);
    }

public:
    ll maximumValueSum(vector<int>& nums, int kk, vector<vector<int>>& edges) {
        n = nums.size();
        for (int& val : nums) a.push_back(static_cast<ll>(val));
        k = kk;
        dp.assign(n, vector<ll>(2, -1));
        return dfs(0, 1);
    }
};
