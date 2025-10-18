// Oct. 17th, 2025

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (k==0) {
            unordered_set<int> s(nums.begin(), nums.end());
            return s.size();
        }
        sort(nums.begin(), nums.end());
        nums[0]-=k;
        int n=nums.size();
        int pen=0;
        for (int i=1; i<n; ++i) {
            if (nums[i]-k == nums[i-1]) {
                nums[i]=nums[i-1]+1;
            }
            // otherwise it must be greater
            // CASE 1: valid gap
            else if (nums[i]+k > nums[i-1]) {
                nums[i]=max(nums[i]-k, nums[i-1]+1);
            }
            // CASE 2: propagate prev, cannot fill, invalid
            else {
                nums[i]=nums[i-1];
                ++pen;
            }
        }

        return nums.size()-pen;
    }
};