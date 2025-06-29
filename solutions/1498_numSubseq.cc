// June 28th, 2025 (daily)

constexpr int MOD = 1e9+7;
using ll = long long;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // exclude the largest k nums that dont satisfy
        sort(nums.begin(), nums.end());

        int n=nums.size();

        // precompute
        vector<int> p(n, 0);    //2^p
        p[0]=1;
        for (int i=1; i<n; ++i) p[i] = (p[i-1]*2)%MOD;

        // int cutoff=n-1;
        int l=0,r=n-1;
        int ans=0;
        while (l<=r) { // 1e6+1e6 doesnt overflow
            if (nums[l] + nums[r] <= target) {
                ans += p[r-l];
                ans %= MOD;
                ++l;
            }
            else {
                --r;
            }
        }

        return ans;
    }
};










// pure formula method fial

// constexpr int MOD = 1e9+7;
// using ll = long long;

// class Solution {
// public:
//     int numSubseq(vector<int>& nums, int target) {
//         // exclude the largest k nums that dont satisfy
//         sort(nums.begin(), nums.end());

//         int n=nums.size();
//         int cutoff=n-1;
//         while (nums[cutoff]+nums[0] > target) { // 1e6+1e6 doesnt overflow
//             cutoff--;
//         }

//         cout << "first cutoff: " << cutoff << endl;

//         // then its just choose or not choose until cutoff
//         // i.e. 2^(cutoff+1)-1
//         ll ans=0;
//         ans=pow(2,cutoff+1)-1;

//         cout << "overcounted: " << ans << endl; 

//         // now slide from the lelft
//         cutoff=0;
//         while (nums[cutoff]+nums[n-1] <= target && cutoff<n-1) ++cutoff;
//         ans-=pow(2,(n-cutoff))-1;

//         cout << "second cutoff: " << cutoff << endl;

//         cout << "addr overcount: " << ans << endl;

//         return ans;
//     }
// };