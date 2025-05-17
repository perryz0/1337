// May 16th, 2025 (daily)
#include <vector>
#include <cstring>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // bucket sort, only three keys
        // unordered_map<int,vector<int>> rwb;
        int rwb[3]; // indices dont matter
        memset(rwb, 0, sizeof(rwb));
        for (int& v : nums) rwb[v]++;
        // for (int& v : nums) rwb[v].push_back(v);
        int n = nums.size();
        // vector<int> res;
        int it = 0;
        for (int i=0; i<=2; ++i) {
            for (int j=0; j<rwb[i]; ++j) {
                nums[it] = i;
                it++;
            }
            // for (int j=0; j<rwb[i].size(); ++j) {
            //     nums[it] = rwb[i][j];
            //     it++;
            // }
        }
    }
};