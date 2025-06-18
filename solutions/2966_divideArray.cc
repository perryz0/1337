// June 17th, 2025 (daily)

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> ans(n/3);
        
        for (int i=0; i<n/3; ++i) {
            for (int j=0; j<3; ++j) {
                int idx = i*(3)+j;
                ans[i].push_back(nums[idx]);
            }
            if (ans[i][2]-ans[i][0] > k) return {};
        }

        return ans;
    }
};