// Oct. 10th, 2025

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> count;
        for (int p : power) {
            count[p]++;
        }
        vector<pair<int, int>> vec = {{-1e9, 0}};
        for (auto& p : count) {
            vec.push_back(p);
        }
        int n = vec.size();
        vector<long long> f(n, 0);
        long long mx = 0;
        for (int i = 1, j = 1; i < n; i++) {
            while (j < i && vec[j].first < vec[i].first - 2) {
                mx = max(mx, f[j]);
                j++;
            }
            f[i] = mx + 1LL * vec[i].first * vec[i].second;
        }
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, f[i]);
        }
        return ans;
    }
};

// using ll = long long;

// class Solution {
// public:
//     long long maximumTotalDamage(vector<int>& power) {
//         sort(power.begin(), power.end());
//         int n=power.size();
//         ll ans=power[n-1];
//         int prev=ans;
//         for (int i=n-2; i>=0; --i) {
//             if (prev != power[i] && prev < power[i]+2) continue;
//             prev = power[i];
//             ans += power[i];
//         }

//         return ans;
//     }
// };