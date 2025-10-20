// Oct. 19th, 2025

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for (const string& s : operations) {
            if (s == "--X" || s == "X--") ans--;
            else ans++;   
        }
        return ans;
    }
};