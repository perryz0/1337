// Aug 6th, 2025

// editorail

class Solution {
private:
    int n;

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();

        // cannot resolve overlaps greedily, because the move(s) after that can be more lucrative
        // (0,0) kid can only walk along the diagonal

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
        }

        auto dp = [&]() -> int {
            vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
            prev[n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; ++i) {
                for (int j = max(n - 1 - i, i + 1); j < n; ++j) {
                    int best = prev[j];
                    if (j - 1 >= 0) {
                        best = max(best, prev[j - 1]);
                    }
                    if (j + 1 < n) {
                        best = max(best, prev[j + 1]);
                    }
                    curr[j] = best + fruits[i][j];
                }
                swap(prev, curr);
            }
            return prev[n - 1];
        };

        ans += dp();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(fruits[j][i], fruits[i][j]);
            }
        }

        ans += dp();
        return ans;
    }
};