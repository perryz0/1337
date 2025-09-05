// Sep. 4th, 2025

class Solution {
private:
    int pc(long long x) {
        int c=0;
        while(x>0){
            x &= (x-1);
            ++c;
        }

        return c;
    }

public:
    int makeTheIntegerZero(long long num1, long long num2) {
        // try k operations; at most 60 per hints/constraints
        if (num2 > num1+1) return -1;
        for (int k=1; k <= 60; ++k) {
            long long t = num1 - (long long)k * num2;
            if (t < 0) continue;                 // cant sum to negative
            int bits = pc(t);
            if (bits <= k && k <= t) return k;
        }
        return -1;
    }
};


// class Solution {
// private:
//     long long target, N2;
//     vector<long long> pows;

//     bool enumerate(int cap) {
//         // greedily add
//         int s=0, c=0;
//         while (c<cap) {
//             // choose the best one
//             for (int i=60; i>=0; --i) {
//                 int curPow=pows[i];
//                 if (curPow + N2 < target-s) {
//                     s += curPow+N2;
//                 }
//             }
//             ++c;
//         }
//         return false;
//     }

// public:
//     int makeTheIntegerZero(int num1, int num2) {
//         target=num1;
//         N2=num2;
//         if (num2 > num1+1) return -1;
        
//         pows = vector<long long>(61,0);
//         pows[0]=1;
//         for (int i=1; i<61; ++i) {
//             pows[i]=pows[i-1]*2;
//         }
//         // for (const long long p : pows) cout << p << " ";
//         // cout << endl;

//         // piece together a summation of -\sum(2^i + num2) with as few terms as possible
//         for (int i=1; i<=60; ++i) {
//             if (enumerate(i)) return i;
//         }

//         return -1;
//     }
// };