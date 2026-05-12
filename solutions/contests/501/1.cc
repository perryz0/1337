class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans=nums;
        reverse(nums.begin(),nums.end());
        for(const int& r : nums) ans.push_back(r);

        return ans;
    }
};
