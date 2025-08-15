// Aug 13rd, 2025

class Solution {
public:
    string largestGoodInteger(string num) {
        set<string> ans;

        char curr = num[0], ctr=1;
        for (int i=1; i<num.length(); ++i) {
            if (num[i] == num[i-1]) ctr++;
            else {
                ctr=1;
                curr=num[i];
            }
            if (ctr == 3) ans.insert(num.substr(i-2, 3));
        }

        return (ans.empty()) ? "" : *ans.rbegin();
    }
};