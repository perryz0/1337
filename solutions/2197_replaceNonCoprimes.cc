// Sep. 15th, 2025

class Solution {
// private:
//     int gcd(int a, int b) {
//         if (a == 0) return b;
//         return gcd(b%a, a);
//     }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int N=nums.size();
        for (int i=1; i<N; ++i) {
            int top = ans[ans.size()-1];
            int cur = nums[i];
            int g =  std::gcd(top,cur);
            while (!ans.empty() && g > 1) {
                // cur = std::lcm(top, cur);
                // lcm(a,b) = (a*b) / gcd(a,b);
                cur = (1LL)*top*cur / g;
                ans.pop_back();
                if (ans.empty()) break;
                top = ans[ans.size()-1];
                g = std::gcd(top,cur);
            }
            ans.push_back(cur);
        }

        return ans;
    }
};