// Aug 12th, 2025

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        // unordered_set<unsigned long> powers;
        for (unsigned long i=1; i<=INT_MAX; i*=3) {
            if (i==n) return true;
            if (i>n) return false;
        }

        // return powers.contains(n);
        return false;
    }
};