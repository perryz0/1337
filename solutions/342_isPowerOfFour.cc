// Aug 14th, 2025

class Solution {
public:
    bool isPowerOfFour(int n) {
        for (unsigned long i=1; i<INT_MAX; i*=4) {
            if (i == n) return true;
            if (i > n) return false;
        }

        return false;
    }
};