// Aug 8th, 2025

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        
        bool setBefore=0;
        for (int i=31; i>=0; --i) {
            uint32_t mask = 1u << i;
            bool currSet = (n & mask) != 0;
            if (currSet & setBefore) return false;
            if (setBefore == 0) setBefore = currSet;
            // cout << "Bit " << i << ": " << currSet << "\n";
        }

        return true;
    }
};