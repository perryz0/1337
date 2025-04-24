// Apr. 23rd, 2025 (daily)

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int,int> mp;
            for (int& num : nums) mp[num]++;
            int tot = mp.size();
    
            int n = nums.size();
            int cnt = 0;
    
            for (int i=0; i<n; ++i) {
                unordered_map<int, int> t;
                int distinct = 0;
    
                for (int j=i; j<n; ++j) {
                    if (++t[nums[j]] == 1) distinct++;
                    if (distinct == tot) cnt++;
                }
            }
    
            return cnt;
        }
    };
    