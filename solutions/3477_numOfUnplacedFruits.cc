// Aug 4th, 2025

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=fruits.size();
        vector<bool> used(baskets.size(), 0);

        for (int i=0; i<fruits.size(); ++i) {
            for (int j=0; j<baskets.size(); ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    ans--;
                    used[j]=true;
                    break;
                }
            }
        }

        return ans;
    }
};