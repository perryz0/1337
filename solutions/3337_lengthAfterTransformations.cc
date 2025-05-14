// May 13th, 2025 (daily)

#define MOD 1000000007
#define ll long long

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<ll>> freqs(1, vector<ll>(26,0));    // 1-col vector
        for (char& c : s) freqs[0][c-'a'] += 1;

        vector<vector<ll>> transform(26, vector<ll>(26, 0));
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<nums[i]; ++j) {
                transform[i][(i+j+1) % 26] += 1;
            }
        }
        vector<vector<ll>> res = mm(freqs, mp(transform, t));

        int tot = 0;
        for (ll& v : res[0]) tot = (tot + v) % MOD;

        return tot;
    }

    vector<vector<ll>> mm(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
        int ar = a.size(), ac = a[0].size(), br = b.size(), bc = b[0].size();
        vector<vector<ll>> res(ar, vector<ll>(bc, 0));
        
        // o(n^3) mm
        for (int i=0; i<ar; ++i) {
            for (int j=0; j<ac; ++j) {
                for (int k=0; k<bc; ++k) {
                    res[i][k] += a[i][j] * b[j][k];
                    res[i][k] %= MOD;
                }
            }
        }
        
        return res;
    }

    vector<vector<ll>> mp(const vector<vector<ll>>& a, int pow) {
        if (pow == 0) {
            vector<vector<ll>> id(26, vector<ll>(26, 0));
            for (int i=0; i<26; ++i) id[i][i]=1;
            return id;
        }
        if (pow == 1) return a;

        vector<vector<ll>> ak2 = mp(a, pow/2);
        if (pow % 2 == 0) return mm(ak2, ak2);
        else return mm(mm(ak2, ak2), a);
    }
};





// convert into matrix exponentiation for o(logn)

// #define MOD 1000000007
// #define ll long long

// class Solution {
// public:
//     int lengthAfterTransformations(string s, int t) {
//         vector<ll> freqs(26,0);
//         for (char& c : s) freqs[c-'a']++;

//         // for (char& c : s) {
//         //     res += findLen(c);
//         // }

//         // sim t
//         for (int i=0; i<t; ++i) {
//             vector<ll> nf(26,0);
//             for (int j=0; j<26; ++j) {
//                 if (j == 25) {
//                     nf[0] = (nf[0]+freqs[25])%MOD;
//                     nf[1] = (nf[1]+freqs[25])%MOD;
//                 }
//                 else {
//                     nf[j+1] = freqs[j];
//                 }
//             }
//             freqs = nf;

//             // cout << c << endl;
//         }

//         int res = 0;
//         for (ll& f : freqs) res = (res+f)%MOD;

//         return res;
//     }

//     // int findLen(char& c) {
//     //     int threshold 
//     // }
// };