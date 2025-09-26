// Sep. 25th, 2025

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans=0;
        int n=nums.size();
        // int l=0, r=n-1;
        // while (l+1<r) {
        //     int remainingGEQ = nums[r]-nums[l];
        //     int upperIdx = 
        // }
        for (int a=0; a<n-2; ++a) {
            for (int b=a+1; b<n-1; ++b) {
                int c_upperbound = nums[a]+nums[b]; // c < a+b
                int idx = lower_bound(nums.begin()+b+1, nums.end(), c_upperbound)-nums.begin()-1;
                if (idx <= b) continue;
                ans += (idx-b);
            }
        }

        return ans;
    }
};