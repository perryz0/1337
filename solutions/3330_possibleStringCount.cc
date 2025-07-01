// June 30th, 2025

class Solution {
public:
    int possibleStringCount(string word) {
        // consecutive chars only, only one type of char everytime
        // consecutive chars+1 (original string)

        int ans=1;
        for (int i=1; i<word.length(); ++i) {
            if (word[i]==word[i-1]) ans++;
        }

        return ans;
    }
};
