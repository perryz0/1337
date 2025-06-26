// June 25th, 2025

using ull = unsigned long long;

class Solution {
// private:
    // ull acc;

    // ull toBin(string num) {
    //     ull acc=0;


    //     return acc;
    // }

public:
    int longestSubsequence(string s, int k) {
        // basically just: find number of 0's, and then
        //  number of 1's that can sandwich in between
        int ans=0;
        for (const char& c : s) if (c == '0') ans++;
        // cout << ans << endl;

        // then just go backwards and check if that substring is valid (i.e. smaller than k)
        ull acc=0;
        int n=s.length();
        for (int i=n-1; i>=0; i--) {
            int deg = n-i-1;
            ull p = pow(2,deg);
            if (p > 10e9) break;
            acc += (s[i]-'0') * p;
            if (acc > k) break;
            if (s[i] == '1') ans++;
            // cout << acc << endl;
        }

        return ans;
    }
};