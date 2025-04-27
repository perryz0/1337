// Apr. 25th, 2025 (daily)

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int res = 0;
            int n = nums.size();
    
            for (int i=0; i<n-2; ++i) {
                if ((double)nums[i] + (double)nums[i+2] == (double)nums[i+1]/2) res++;
            }
    
            return res;
        }
    };