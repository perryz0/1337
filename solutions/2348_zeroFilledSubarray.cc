// Aug. 18th, 2025

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // 1+2+3+...sizeof(current subarray)
        long long ans=0;
        long long cnt=0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == 0) cnt++;
            else cnt=0;
            ans += cnt;
        }

        return ans;
    }
};