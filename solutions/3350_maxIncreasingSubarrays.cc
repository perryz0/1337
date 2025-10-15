// Oct. 14th, 2025

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int primary=1, backup=0;
        int N=nums.size();
        int ans=1;
        for (int i=1; i<N; ++i) {
            if (nums[i]>nums[i-1]) {
                ++primary;
            }
            else {
                backup=primary; //must commit
                primary=1;
            }
            ans=max(ans, min(primary, backup));
            ans=max(ans, primary/2);    // the running primary might never pass to backup
        }

        return ans;
    }
};