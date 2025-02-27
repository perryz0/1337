// Feb. 25th, 2025 (daily)

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int mx = nums[0], mn = nums[0];
            int n = nums.size();
            int max_curr = mx, min_curr = mn;
    
            for (int i = 1; i<n; ++i) {
                max_curr = max(nums[i], max_curr+nums[i]);
                min_curr = min(nums[i], min_curr+nums[i]);
                mx = max(mx, max_curr); mn = min(mn, min_curr);
            }
    
            return max(mx, abs(mn));
        }
    };