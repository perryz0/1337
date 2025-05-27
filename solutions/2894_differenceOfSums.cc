// May 26th, 2025 (daily)

class Solution {
public:
    int differenceOfSums(int n, int m) {
        // n2 = m+2m+...+km = n/m*(n/m+1)m/2, where k = floor(n/m)
        // n1 = tot - 2n2 = n(n+1)/2 - 2n2
        // int n2 = n/m*((n/m)+1)*m/2;
        return n*(n+1)/2 - n/m*((n/m)+1)*m;
    }
};


        // o(n) shit
        // // 1000*1000 = 10e6, so sum fits in int
        // int n1=0, n2=0;
        // for (int i=1; i<=n; ++i) {
        //     if (i%m) n1+=i;
        //     else n2+=i;
        // }

        // return n1-n2;