// Apr. 14th, 2025 (daily)

#define ll long long

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        ll cnt = 0;
        int n = nums.size();
        ll tot = 0;
        int l = 0;

        for (int r = 0; r<n; ++r) {
            tot += freqs[nums[r]];
            freqs[nums[r]]++;

            while (tot >= k) {
                cnt += n-r;
                tot -= freqs[nums[l]]-1;
                freqs[nums[l]]--;
                l++;
            }
        }

        return cnt;
    }
};