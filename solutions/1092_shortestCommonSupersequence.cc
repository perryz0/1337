// Feb. 26th, 2025 (daily)
//hard as shit

class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            // retval is AT LEAST as long as the longest str out of str1 and str2
    
            // dp the lengths instead of the full substrs
            int n = str1.length(), m = str2.length();
            
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    if (i == 0) dp[i][j] = j;
                    else if (j == 0) dp[i][j] = i;
                    else if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                    else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
    
    
            // now backtrack
            int i = n, j = m;
            string result = "";
            
            while (i > 0 && j > 0) {
                if (str1[i-1] == str2[j-1]) {
                    result += str1[i - 1];
                    i--; j--;
                } else if (dp[i-1][j] < dp[i][j-1]) {
                    result += str1[i-1];
                    i--;
                } else {
                    result += str2[j-1];
                    j--;
                }
            }
    
            // append remainders
            while (i > 0) result += str1[--i];
            while (j > 0) result += str2[--j];
    
            reverse(result.begin(), result.end());  // rev because string is backwardsa
    
            return result;
        }
    };
    
    
            // MLE CPP RIP
            // // dp top down caching (neetcode soln)
    
            // int n = str1.length(), m = str2.length();
    
            // vector<string> prev(m+1);
    
            // for (int i = 0; i<m; ++i) prev[i] = str2.substr(i);
            // prev[m] = "";
    
            // vector<string> cur(m+1, "");
            // for (int i = n-1; i>=0; i--) {
            //     cur[m] = str1.substr(i); 
            //     for (int j = m-1; j>=0; j--) {
            //         if (str1[i] == str2[j]) cur[j] = str1[i] + prev[j+1];
            //         // otherwise not diagonal, consider both up or down
            //         else cur[j] = ((str1[i] + prev[j]).length() < (str2[j] + cur[j+1]).length()) ? str1[i] + prev[j] : str2[j] + cur[j+1];
            //     }
            //     prev = cur;
            // }
    
            // return cur[0];