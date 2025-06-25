// June 24th, 2025

// editorial soln 1 rip, sad fail

class Solution {
public:
    int f(vector<int>& nums2, long long x1, long long v) {
        int n2 = nums2.size();
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x1 >= 0 && nums2[mid] * x1 <= v ||
                x1 < 0 && nums2[mid] * x1 > v) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (x1 >= 0) {
            return left;
        } else {
            return n2 - left;
        }
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i = 0; i < n1; i++) {
                count += f(nums2, nums1[i], mid);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

// using ll = long long;
// using i128 = __int128_t;

// class Solution {
// private:
//     vector<int> n1, n2; // these are sorted

//     ll ceilDiv(ll a, ll b) {
//         if (b == 0) throw;
//         return a / b + ((a % b != 0) && ((a > 0) == (b > 0)));
//     }

//     int nLeqProd(ll target) {
//         int cnt=0;
//         int L2=n2.size();

//         for (const int& x : n1) {
//             if (x < 0) {
//                 ll bound = ceilDiv(target, x);
//                 cnt += L2 - (lower_bound(n2.begin(), n2.end(), bound) - n2.begin());
//             }
//             else if (x == 0) { // 1<=k<=L1*L2, so this target >= 0 is guaranteed? (or not)
//                 if (target >= 0) cnt += L2;
//                 // cnt += L2;
//             }
//             else {
//                 ll bound = target / x; // Floor
//                 cnt += (upper_bound(n2.begin(), n2.end(), bound+1) - n2.begin());
//             }
//             cout << target << "," << cnt << endl;
//         }

//         return cnt;
//     }

// public:
//     long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
//         n1=nums1, n2=nums2;

//         ll l=-1e10, r=1e10;

//         while (l<r) {
//             ll mid = (ll)((i128)l+((i128)r-l)/2);

//             if (nLeqProd(mid) >= k) {
//                 r=mid;
//             } else {
//                 l=mid+1;
//             }
//         }

//         return l;
//     }
// };