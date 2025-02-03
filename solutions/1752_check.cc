// Feb. 1st, 2025 (daily)

class Solution {
public:
    bool check(vector<int>& nums) {
        int prev = nums[0];
        int n = nums.size();
        bool switched = 0;

        for (int i = 1; i < n; ++i) {
            if (switched && prev > nums[i]) return false;
            if (prev > nums[i]) switched = true;
            prev = nums[i];
        }

        if (switched && nums[0] < nums[n-1]) return false;

        return true;
    }
};