// July 21st, 2025

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // max subarray sum but with uniqueness
        // sliding window
        int l=0;
        int n=nums.size();
        int ans=0, running=0;
        unordered_set<int> s;
        for (int r=0; r<n; ++r) {
            while (s.contains(nums[r])) {
                s.erase(nums[l]);
                running -= nums[l];
                ++l;
            }
            running += nums[r];
            s.insert(nums[r]);
            ans=max(ans,running);
        }

        return ans;
    }
};
