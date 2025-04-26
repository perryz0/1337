// Apr. 24th, 2025 (daily)

#define ll long long

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        ll tot = 0;
        int n = nums.size();

        unordered_map<int, ll> ps;
        ps[0]=1;    // 0%k==k
        int curr=0;

        for (int& num : nums) {
            if (num % modulo == k) curr++;
            tot += ps[(curr-k+modulo) % modulo];
            ps[curr % modulo]++;
        }

        return tot;
    }
};