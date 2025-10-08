// Oct. 7th, 2025

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int m=potions.size();
        for (const int& s : spells) {
            long target = ceil((success/(double)s));
            int geq = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
            ans.push_back(m-geq);
        }

        return ans;
    }
};