// July 30th, 2025

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        // int ans=0;
        unordered_set<int> seen;
        seen.insert(0);
        for (const int x : arr) {
            unordered_set<int> curr;
            for (const int& y : seen) curr.insert(x|y);
            curr.insert(x);
            seen=curr;
            for (const int& currVals : curr) ans.insert(currVals);      // deduplication
        }

        return ans.size();
    }
};