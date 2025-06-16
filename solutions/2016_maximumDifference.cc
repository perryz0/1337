// June 15th, 2025 (daily)

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int m=nums[0];
        int n=nums.size();
        int ans=-1;
        for (int i=1; i<n; ++i) {
            if (nums[i]>m) ans=max(nums[i]-m,ans);
            m=min(nums[i],m);
        }

        return ans;
    }
};