// June 18th, 2025 (daily)

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=1;

        int l=0;
        int r=1;
        int n=nums.size();
        while (r<n) {
            if (nums[r]-nums[l] > k) {
                // if (r-l==1) return -1;
                l=r;
                ans++;
            }
            // else if () {

            // }
            r++;
        }

        return ans;
    }
};