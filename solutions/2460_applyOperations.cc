// Feb. 28th, 2025 (daily)

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i<n; ++i) {
            if (nums[i] == nums[i-1]) {
                nums[i-1] = nums[i-1]*2;
                nums[i] = 0;
            }
        }

        vector<int> res(n, 0);

        int iter = 0;
        for (int i = 0; i<n; ++i) {
            if (nums[i] != 0) {
                res[iter] = nums[i];
                iter++;
            }
        }
        return res;
    }
};