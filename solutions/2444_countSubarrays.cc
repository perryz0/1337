// Apr. 25th, 2025 (daily)
//revisit again

#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        ll ans = 0;
        
        int lastMin = -1, lastMax = -1, lastInv = -1;
        
        for (int i=0; i<n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastInv = i;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            ans += max(0, min(lastMin, lastMax) - lastInv);
        }
        
        return ans;
    }
};
