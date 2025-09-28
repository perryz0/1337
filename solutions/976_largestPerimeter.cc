// Sep. 27th, 2025

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans=0;
        int N=nums.size();
        sort(nums.begin(), nums.end());

        for (int i=N-1; i>=2; --i) {
            int part = nums[i-2]+nums[i-1];
            if (part > nums[i]) return part+nums[i];
        }

        return ans;

        // for (int i=0; i<N; ++i) {
        //     for (int j=i+1; j<N;++j) {
        //         auto k = lower_bound(nums.begin()+j, nums.end(), nums[i]+nums[j]);
        //         if (k == nums.end()) break;
        //         int idx = k-nums.begin();
        //         if (nums[idx] > nums[i] + nums[j]) idx -= 1;
        //         if (idx <= j) break;
        //         else ans=max(ans, nums[i]+nums[j]+nums[idx]);
        //     }
        // }

        return ans;
    }
};