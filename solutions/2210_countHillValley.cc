// July 26th, 2025

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for (int i=1; i<n-1; ++i) { // fix the mid
            int l=i-1;
            int r=i+1;
            while (r<n && nums[r] == nums[i]) {
                ++r;
            }
            if (r == n) break;
            i=r-1;
            if (nums[l] < nums[i] && nums[r] < nums[i]) ans++;
            else if (nums[l] > nums[i] && nums[r] > nums[i]) ans++;
        }

        return ans;
    }
};