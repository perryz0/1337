// Apr. 27th, 2025 (daily)

#define ll long long

// all nums[i] are strictly positive, so sliding window will be nice

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<ll> ps(n);
        ps[0]=nums[0];

        // prefix sum, pass 1
        for (int i=1; i<n; ++i) {
            ps[i] = ps[i-1]+nums[i];
        }

        // sliding window to dynamically count subarrays as we expand to the right
        // # subarrays = r-l+1 for each valid window, other cases are covered by PREV windows
        int l=0;
        ll res = 0;
        for (int r=0; r<n; ++r) {
            while ((ps[r]-(l>0 ? ps[l-1] : 0))*(r-l+1) >= k) {
                l++;
            }

            res += (r-l+1);
        }

        // if ((ps[n-1])*(n-1-l+1) < k) res += (n-1-l+1);

        // for (int r=0; r<n; ++r) {
        //     ll window = ps[r] - (l>0 ? ps[l-1] : 0);
        //     while (window * (r-l+1) >= k) {
        //         l++;
        //         window = ps[r] - (l > 0 ? ps[l-1] : 0);
        //     }
        //     res += (r-l+1);
        // }

        return res;
    }
};