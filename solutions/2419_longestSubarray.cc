// July 29th, 2025

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int goal=0;
        for (const int& n : nums) goal=max(goal,n); // max num itself is max bitwise AND
        int cnt=0;
        int ans=1;
        for (const int& n : nums) {
            goal=max(goal,n);
            ans=max(ans, cnt);
            if (n==goal) ++cnt;
            else cnt = 0;
        }

        return max(ans,cnt);
    }
};