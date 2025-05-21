// May 18th, 2025 (daily)

class Solution {
public:
    string triangleType(vector<int>& nums) {
        // if (nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";

        for (int i=0; i<3; ++i) {
            int sum = 0;
            for (int j=0; j<3; ++j) {
                sum += (i != j) ? nums[j] : 0;
            }
            // cout << sum << endl;
            if (sum <= nums[i]) return "none";
        }

        unordered_set<int> s;
        for (int& n : nums) s.insert(n);

        if (s.size() == 1) return "equilateral";
        if (s.size() == 2) return "isosceles";
        if (s.size() == 3) return "scalene";

        return "none";
    }
};