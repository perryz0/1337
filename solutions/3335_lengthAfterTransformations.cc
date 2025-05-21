// May 12th, 2025 (daily)

#define MOD 1000000007
#define ll long long

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<ll> freqs(26,0);
        for (char& c : s) freqs[c-'a']++;

        // for (char& c : s) {
        //     res += findLen(c);
        // }

        // sim t
        for (int i=0; i<t; ++i) {
            vector<ll> nf(26,0);
            for (int j=0; j<26; ++j) {
                if (j == 25) {
                    nf[0] = (nf[0]+freqs[25])%MOD;
                    nf[1] = (nf[1]+freqs[25])%MOD;
                }
                else {
                    nf[j+1] = freqs[j];
                }
            }
            freqs = nf;

            // cout << c << endl;
        }

        int res = 0;
        for (ll& f : freqs) res = (res+f)%MOD;

        return res;
    }

    // int findLen(char& c) {
    //     int threshold 
    // }
};