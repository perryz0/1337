// Feb. 3rd, 2025 (daily)

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int runningSum = prev, res = prev;

        for (int i = 1; i < n; ++i) {
            if (prev >= nums[i]) { res = max(res, runningSum); runningSum = 0; }
            prev = nums[i];
            runningSum += nums[i];
        }

        return max(res, runningSum);
    }
};