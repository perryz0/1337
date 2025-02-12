// Feb. 11th, 2025 (daily)

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> digitSums; // {sum: idx}

        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            string n = to_string(nums[i]);
            cur = 0;
            for (char& c : n) {
                cur += c-'0';
            }
            digitSums[cur].push_back(nums[i]);
        }

        int mx = -1;
        for (auto& sum : digitSums) {
            if (sum.second.size() < 2) continue;
            sort(sum.second.begin(), sum.second.end());
            mx = max(mx, sum.second[sum.second.size()-1] + sum.second[sum.second.size()-2]);
        }

        return mx;
    }
};