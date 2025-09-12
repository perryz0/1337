// Sep. 11th, 2025

class Solution {
public:
    bool doesAliceWin(string s) {
        string vows="aeiou";
        for (const char& v : vows) if (s.find(v) != string::npos) return true;

        return false;
        // int cnt=0;
        // for (const char& c : s) if (v.find(c) != string::npos) ++cnt;

        // return (cnt!=0);
    }
};