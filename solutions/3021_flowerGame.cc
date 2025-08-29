using ll = long long;

class Solution {
public:
    long long flowerGame(int n, int m) {
        return (ll)m*n/2;
        // so just find all odd sums >= 3
        // if (n>m) return flowerGame(m,n);
        // if (m>n) return flowerGame(m,n);

        // ll ans=0;
        // for (int i=1; i<=n; ++i) {
        //     // odd, m=2,4,6...m
        //     if (i%2) {
        //         ans += (m)/2;
        //     }

        //     // even, m=1,3,5...m
        //     else {
        //         ans += (m/2);
        //     }
        // }

        // // for (int i=1; i<=m; ++i) {
        // //     // odd, m=1,3,5...m
        // //     if (i%2) {
        // //         ans += (n+1)/2;
        // //     }

        // //     // even, m=2,4,6...m
        // //     else {
        // //         ans += (n/2);
        // //     }
        // // }

        // return ans;
    }
};