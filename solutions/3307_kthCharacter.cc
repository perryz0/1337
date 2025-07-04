// July 3rd, 2025

using ll = long long;
using u128 = __uint128_t;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        --k;
        int cur=0;
        for (int i=0; i<operations.size(); ++i) {
            if ((u128(1) << i) & u128(k)) {
                if (operations[i]==1) cur = (cur+1)%26;
            }
        }

        return cur+'a';
    }
};