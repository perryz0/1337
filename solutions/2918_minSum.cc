// May 10th, 2025 (daily)

#define ll long long

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1 = 0, s2 = 0;
        int z1 = 0, z2 = 0;
        bool has1 = 0, has2 = 0;
        for (int& n : nums1) {
            s1 += (n == 0) ? 1 : n;
            if (n == 0) {
                z1++;
                has1 = true;
            }
        }

        for (int& n : nums2) {
            s2 += (n == 0) ? 1 : n;
            if (n == 0) {
                z2++;
                has2 = true;
            }
        }

        if (s1 == s2) return s1;

        if (min(s1,s2) == s1) {
            if (z1 <= s2-(s1-z1)) {
                if (!has1) return -1;
                return s2;
            }
        } else {
            if (z2 <= s1-(s2-z2)) {
                if (!has2) return -1;
                return s1;
            }
        }

        return -1;
    }
};