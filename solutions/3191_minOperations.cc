# Mar. 18th, 2025 (daily)

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int cnt = 0;
            for (int i = 0; i < nums.size()-2; ++i) {
                if (nums[i] == 0) {
                    cnt++;
                    nums[i+1] = !nums[i+1];
                    nums[i+2] = !nums[i+2];
                }
            }
    
            for (int i = nums.size()-2; i<nums.size(); ++i) {
                if (nums[i] == 0) return -1;
            }
    
            return cnt;
        }
    };