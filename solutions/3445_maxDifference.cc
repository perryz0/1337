// June 10th, 2025 (daily)

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size(), ans = INT_MIN;

        for (int a = 0; a < 5; ++a) {
            for (int b = 0; b < 5; ++b) {
                if (a == b) continue;

                int cnt_a = 0, cnt_b = 0, prev_a = 0, prev_b = 0, left = -1;
                int best[4];
                fill(begin(best), end(best), 1e9);

                for (int r = 0; r < n; ++r) {
                    cnt_a += (s[r] - '0' == a);
                    cnt_b += (s[r] - '0' == b);

                    while (r - left >= k && cnt_b - prev_b >= 2) {
                        int st = ((prev_a & 1) << 1) | (prev_b & 1);
                        best[st] = min(best[st], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] - '0' == a);
                        prev_b += (s[left] - '0' == b);
                    }

                    int cur = ((cnt_a & 1) << 1) | (cnt_b & 1);
                    int flip = cur ^ 2;

                    if (best[flip] != 1e9) {
                        ans = max(ans, cnt_a - cnt_b - best[flip]);
                    }
                }
            }
        }

        return ans;
    }
};







// give up lol contest rating 2693

// class Solution {
// public:
//     int maxDifference(string s, int k) {
//         int n=s.length();
//         vector<vector<int>> ps(5, vector<int>(n, 0));
//         ps[s[0]-'0'][0] = 1;

//         // calculate the prefix freqs
//         for (int i=1; i<n; ++i) {
//             char c = s[i];
//             for (int j=0; j<5; ++j) {
//                 ps[j][i] = ps[j][i-1];
//                 if (c-'0' == j) ++ps[j][i];
//             }
//         }

//         for (int i=0; i<5; ++i) {
//             for (int j=0; j<n; ++j) {
//                 cout << ps[i][j] << " ";
//             }
//             cout << endl;
//         }

//         // even must be >=2, since 0 should not count for the given inputs
//         int ans=INT_MIN;
//         int iter=0;
//         for (int i=0; i<5; ++i) {
//             for (int j=i+1; j<5; ++j) {
//                 // sliding window (for ps between char i and char j)
//                 cout << iter++ << endl;
//                 cout << ans << endl;

//                 // char i is even (f_j - f_i)
//                 for (int y=n-1; y>=0; --y) {    // backwards for odd (f_j % 2 == 1)
//                     if (ps[j][y]%2 == 1) {
//                         cout << "char" << j << " : " << ps[j][y] << endl;
//                         // int shrink=0;
//                         for (int z=0; z<=y-k+1; ++z) {   // forward for even (2)
//                             // if (s[z]-'0' == j) shrink--;
//                             if (ps[i][z] == 2) {
//                                 cout << "char" << i << " : " << ps[i][y] << endl;
//                                 ans=max(ans, ps[j][y]-ps[i][z]);
//                                 break;
//                             }
//                         }
//                         // break;
//                         // another case here: the max_odd idx might left side of the min_even
//                         int a=n-k, max_odd = ps[j][a];
//                         while (a >= 1 && max_odd == ps[j][a-1]) {
//                             a--;
//                         }
//                         // now we fixed the max_odd for this case, now sliding window to the right
//                         for (int b=a+k-1; b<n; ++b) {
//                             if (ps[i][b] % 2 == 0 && ps[i][b] != 0) {
//                                 ans=max(ans, ps[i][a]-ps[i][b]);
//                             }
//                         }
//                     }
//                 }

//                 // char j is even (f_i - f_j)
//                 for (int y=n-1; y>=0; --y) {    // backwards for odd (f_i % 2 == 1)
//                     if (ps[i][y]%2 == 1) {
//                         // int shrink=0;
//                         for (int z=0; z<=y-k+1; ++z) {   // forward for even (2)
//                             // if (s[z]-'0' == j) shrink--;
//                             if (ps[j][z] == 2) {
//                                 ans=max(ans, ps[i][y]-ps[j][z]);
//                                 break;
//                             }
//                         }
//                     }
//                 }

//                 cout << "------------------" << endl;
//             }
//         }

//         return ans;
//     }
// };