// Sep. 29th, 2025

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            int prev=nums[nums.size()-1];
            for (int i=nums.size()-1; i>=1; --i) {
                int s=(prev+nums[i-1])%10;
                prev=nums[i-1];
                nums[i-1]=s;
            }
            nums.pop_back();
        }

        return nums[0];
    }
};