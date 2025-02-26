// Feb. 24th, 2025 (daily)

#define ll long long
#define MOD 1000000007

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll ps=0;
        int odds=0, evens=1;    // ps=0 is even
        ll cnt=0;

        for (int n : arr) {
            ps=(ps+n)%MOD;
            if (ps%2==0) {
                cnt+=odds;
                evens++;
            } else {
                cnt+=evens;
                odds++;
            }

            cnt%=MOD;
        }

        return cnt;
    }
};