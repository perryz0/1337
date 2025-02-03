// Jan. 31st, 2025 (daily)

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool mask = 1 & nums[0];
        bool next;
        for (int i = 1; i < nums.size(); ++i) {
            next = 1 & nums[i];
            if (mask == next) return false;
            mask = next;
        }

        return true;
    }
};