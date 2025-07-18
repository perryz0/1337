// July 16th, 2025

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for (int i=0; i<n; ++i) nums[i] %= k;

        // cout << ".." << endl;

        for (int i=0; i<k; ++i) {
            vector<int> dp(k, 0);
            for (int& num : nums) {
                int prev = (i - num + k)%k;
                dp[num] = max(dp[num], dp[prev]+1);
            }

            // find the max
            for (int i=0; i<k; ++i) ans = max(ans, dp[i]);
        }


        return ans;
    }
};





// class Solution {
// private:
//     int dp[1001];   // maxes from modulo [0...k-1]

// public:
//     int maximumLength(vector<int>& nums, int k) {
//         int ans = 0;
//         memset(dp, 0, sizeof(dp));

//         // sub[0]+sub[1]%k == sub[1]+sub[2]%k --> sub[0]%k == sub[2]%k
//         int pattern[2] = {0,1};
//         int n = nums.size();

//         for (int i = 0; i < k; ++i) {
//             for (const int& p : pattern) {
//                 int cnt = 0;
//                 int it = 0;

//                 while (it < n && nums[it]%2 != p) ++it;
//                 if (it == n) continue;  // prevent out-of-bounds
//                 ++cnt;
//                 int first = nums[it++];

//                 while (it < n && (nums[it] + first)%k != i) ++it;
//                 if (it == n) continue;
//                 ++cnt;
//                 int sec = nums[it++];

//                 for (; it < n; ++it) {
//                     if (first%k == nums[it]%k) {
//                         first = sec;
//                         sec = nums[it];
//                         ++cnt;
//                     }
//                 }

//                 dp[i] = max(dp[i], cnt);
//             }
//         }

//         // findmax
//         for (const int& m : dp) ans = max(m, ans);

//         return ans;
//     }
// };
