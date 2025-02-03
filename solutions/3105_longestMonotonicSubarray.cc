// Feb. 2nd, 2025 (daily)

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int decCnt = 1, incCnt = 1;
        int maxDec = 1, maxInc = 1;
        int curDec = nums[0], curInc = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; ++i) {
            if (curDec <= nums[i]) { maxDec = max(maxDec, decCnt); decCnt = 0; }
            if (curInc >= nums[i]) { maxInc = max(maxInc, incCnt); incCnt = 0; }
            curDec = nums[i]; curInc = nums[i];
            decCnt++; incCnt++;
        }

        maxDec = max(maxDec, decCnt);
        maxInc = max(maxInc, incCnt);

        return max(maxDec, maxInc);
    }
};