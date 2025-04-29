// Apr. 28th, 2025 (daily)

#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;

        for (int& num : nums) mx = max(mx, num);

        ll res = 0;
        int l = 0;
        int n = nums.size();
        
        int oc = 0;
        for (int r=0; r<n; ++r) {
            if (nums[r] == mx) ++oc;
            while (oc >= k) {
                if (nums[l] == mx) --oc;
                l++;
            }
            res += l;
        }

        return res;
    }
};