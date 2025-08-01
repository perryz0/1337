// July 31st, 2025

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // ans.clear();
        // n=numRows;
        vector<vector<int>> ans;

        // generate the structure
        for (int i=0; i<numRows; ++i) {
            vector<int> lvl(i+1,1);
            ans.push_back(lvl);
        }

        // start backtracking
        // backtrack(0);

        // just tabulate
        for (int x=2; x<numRows; ++x) {
            for (int i=1; i<ans[x].size()-1; ++i) {
                ans[x][i] = ans[x-1][i-1] + ans[x-1][i];
            }
        }

        return ans;
    }
};