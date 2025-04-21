// Apr. 20th, 2025 (daily)

#define ll long long

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll curr = 0;
        ll mn = 0, mx = 0;

        for (int& d : differences) {
            curr += d;
            mn = min(mn, curr);
            mx = max(mx, curr);
        }

        return max(0LL, (ll)upper-mx-(ll)lower+mn+1);
    }
};





        // cout << top << endl;

        // int bot = upper;

        // while (top > upper) {
        //     cout << bot << endl;
        //     top--;
        //     bot--;
        // }

        // while (bot > lower) {
        //     bot--;
        //     res++;
        // }