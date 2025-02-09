// Feb. 8th, 2025 (daily)

class Solution {
    public:
        using ll = long long;
    
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int, int> diffs;  // {nums[i]-i : cnt}
    
            // total possible pairs = (nums.size() choose 2)
            // ans = total possible - good pairs
    
            // find cases where nums[j]-j = nums[i]-i
            for (int i = 0; i < nums.size(); ++i) diffs[nums[i]-i]++;
    
            ll complement = 0;
            for (auto& diff : diffs) {
                if (diff.second < 2) continue;
                complement += (ll)diff.second*(diff.second-1)/2;
            }
    
            return ((nums.size()*(nums.size()-1))/2) - complement;
        }
    };