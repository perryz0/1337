// Sep. 6th, 2025

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for (int i=-n/2; i<=n/2; ++i) {
            if (i==0 && n%2==0)continue;
            ans.push_back(i);
        }

        return ans;
    }
};