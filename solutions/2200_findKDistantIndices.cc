// June 23rd, 2025 (daily)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            int j=(i-k>=0) ? i-k : 0;
            for (; abs(j-i)<=k && j<n; ++j) {
                // if (i==j) continue;
                if (nums[j] == key) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};