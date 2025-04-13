// Apr. 12th, 2025 (daily)

#define M 1000000007
#define ll long long

class Solution {
public:
    int countGoodNumbers(long long n) {
        // even = 0,2,4,6,8
        // prime = 2,3,5,7

        ll evencnt = (n+1)/2;
        ll oddcnt = n/2;

        return (expo(5, evencnt) * expo (4, oddcnt))%M;
    }

    ll expo(ll base, ll exp) {
        ll res = 1;
        base%=M;
        
        while (exp > 0) {
            if (exp%2==1) res = (res*base)%M;
            base = (base*base)%M;
            exp/=2;
        }

        return res;
    }
};













// bf doesnt work lol
// #define M 1000000007
// #define ll long long

// class Solution {
// public:
//     int countGoodNumbers(long long n) {
//         ll cnt = 1;

//         // even = 0,2,4,6,8
//         // prime = 2,3,5,7

//         for (ll i = n-1; i>=0; --i) {
//             // cout << i << endl;
//             if (i == n && i%2 == 0) {
//                 cnt *= 4;
//             }
//             else {
//                 if (i%2 == 0) {
//                     cnt = (cnt*5)%M;
//                 }

//                 else {
//                     cnt = (cnt*4)%M;
//                 }
//             }
//         }

//         return static_cast<int>(cnt);
//     }
// };