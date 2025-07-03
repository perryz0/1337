// July 2nd, 2025

string generate() {
    // len = 2^ops
    // ops=0, len = 2^0 = 1, "a"
    // ops=1, len = 2^1 = 2, "b"
    // ....
    /***
    "a"
    "ab"
    "abbc"
    "abbcbccd"
    **/
    int pow[10] = {1,2,4,8,16,32,64,128,256,512};

    string s = "a";
    // len <= k, max(k) = 500, and log2(500) < 9
    for (int i=1; i<=9; ++i) {
        int sz=pow[i];
        for (int j=sz/2; j<sz; ++j) {
            int idx = j-sz/2;
            s.push_back(static_cast<char>(s[idx]+1));
        }
    }

    // cout << s << endl;
    return s;
}

const string s = generate();    // generate once, use for all

class Solution {
public:
    char kthCharacter(int k) {
        return s[k-1];
    }
};