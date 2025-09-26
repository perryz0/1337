// Sep. 24th, 2025

class Solution {
// private:
//     vector<int> shortests;

//     void dfs(pair<int,int> curIdx, int curSum, int start) {
//         auto [r,c] = curIdx;
//         if (r==0 && c==0) {
//             shortests[start]=curSum;
//             return;
//         }

//         // otherwise 
//     }
private:
    vector<vector<int>> dp, T;

    int dfs(pair<int,int> curIdx) {
        auto [r, c] = curIdx;

        // base case: bottom row
        if (r == (int)T.size() - 1) return T[r][c];

        // already computed?
        if (dp[r][c] != INT_MAX) return dp[r][c];

        // recurse on the two options
        int left = dfs({r+1, c});
        int right = dfs({r+1, c+1});

        return dp[r][c] = T[r][c] + min(left, right);
    }

    // void dfs(pair<int,int> curIdx) {
    //     auto [r,c] = curIdx;
        // cout << "rows and cols: " << r << "," << c << endl;
        // if (r==dp.size()) return;
        // // otherwise get the best prev (one of 2 options)

        // int bestPrev = (c==0) ? dp[r-1][c] : (c==dp[r].size()-1) ? dp[r-1][c-1] : min(dp[r-1][c], dp[r-1][c-1]);
        // // cout << "bestPrev and currCell: " << bestPrev << "," << T[r][c] << endl;
        // dp[r][c] = bestPrev+T[r][c];

        // dfs({r+1,c});
        // if (r != dp.size()-1) dfs({r+1,c+1});
    // }

    void PRINT(vector<vector<int>> V) {
        for (const auto& v : V) {
            cout << "[";
            for (const int& e : v) cout << e << " ";
            cout << "]" << endl;
        }
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // // dfs from the bottom to the top? the heuristic is friendly for this
        int n=triangle.size();
        if (n==1) return triangle[0][0];
        T=triangle;
        // shortests.assign(n, INT_MAX);
        // // starting would be cell[n-1][i];
        // for (int i=0; i<n; ++i) {
        //     dfs({n-1, i}, triangle[n-1][i], i);
        // }
        dp.assign(n, {});
        for (int i=0; i<n; ++i) dp[i].assign(triangle[i].size(), INT_MAX);

        // start DFS from the top
        return dfs({0, 0});
        // dp[0][0]=triangle[0][0];
        // // PRINT(dp);
        // for (int i=0; i<2; ++i) dfs({1, i});
        // // dfs({1,0});

        // int ans=INT_MAX;
        // for (int i=0; i<n; ++i) ans=min(ans, dp[n-1][i]);

        // return ans;
    }
};