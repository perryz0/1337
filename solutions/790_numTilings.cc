// May 4th, 2025 (daily)

#define MOD 1000000007
#define ll long long

class Solution {
public:
    int numTilings(int n) {
        //figure out the formula lol, combinatorics?
        //actually no its dp lol
        //n=1, out=1
        //n=2, out=2
        //n=3, out=5
        //n=4, out=11=(5*2)+1
        //n=5, out=24=(11*2)+2
        //n=6, out=53=(24*2)+5
        //n=7, out=117=(53*2)+11
        //n=8, out=258=(117*2)+24
        //n=9, out=

        // // tabulation (already awesomeeeee)
        // ll ans[1001];
        // ans[1]=1, ans[2]=2, ans[3]=5;
        // for (int i=4; i<1001; ++i) {
        //     ans[i] = (ans[i-1]*2+ans[i-3])%MOD;
        // }
        // return ans[n];

        // max space opt, sliding integers
        ll three=1, two=2, one=5;   // i-3,i-2,i-1
        if (n==1) return three;
        if (n==2) return two;
        if (n==3) return one;
        for (int i=4; i<=n; ++i) {
            ll tmp = (one*2+three)%MOD;
            three=two;
            two=one;
            one=tmp;
        }

        return one;
    }
};