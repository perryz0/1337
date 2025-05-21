// May 14th, 2025 (daily)

#define pb push_back

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // o(n) space
        // int flips = 1;
        vector<string> res;
        res.pb(words[0]);
        // bool curr = groups[0];
        int g = groups.size();
        for (int i=1; i<g; ++i) {
            if (groups[i-1] != groups[i]) {
                // curr = groups[i];
                // flips++;
                res.pb(words[i]);
            }
        }

        // cout << flips << endl;

        // vector<stirng

        return res;
    }
};



        // // can do it inplace, but shitty time if n is large
        // // int g = groups.size();
        // bool curr = groups[0];
        // for (int i=1; i<groups.size(); ++i) {
        //     if (curr == groups[i]) {
        //         words.erase(words.begin()+i);
        //         groups.erase(groups.begin()+i);
        //         i--;
        //     } else {
        //         curr = groups[i];
        //     }
        // }

        // return words;