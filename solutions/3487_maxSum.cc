// July 24th, 2025

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans=0;
        int MAX=INT_MIN;
        unordered_set<int> s;
        for (const int& num : nums) {
            MAX=max(MAX,num);
            if (s.contains(num) || num <= 0) continue;
            ans += num;
            s.insert(num);
        }

        return (MAX<0) ? MAX : ans;
    }
};