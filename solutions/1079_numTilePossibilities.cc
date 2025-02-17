// Feb. 16th, 2025 (daily)

class Solution {
    public:
        int numTilePossibilities(string tiles) {
            vector<int> freqs(26, 0);
            for (char c : tiles) freqs[c - 'A']++;
    
            return backtrack(freqs);
        }
    
        int backtrack(vector<int>& freqs) {
            int cnt = 0;
    
            for (int i = 0; i<26; ++i) {
                if (freqs[i]>0) {
                    freqs[i]--;
                    cnt += 1+backtrack(freqs);
                    freqs[i]++;
                }
            }
    
            return cnt;
        }
    };
    
    
            // multinomial?
            // vector<int> freqs(26, 0);
            // int n = tiles.length();
    
            // for (char& c : tiles) freqs[c-'A']++;
    
            // int res = 1;
    
            // for (int j = n; j>=2; --j) res *= j;
            // for (int j = 0; j<26; ++j) {
            //     for (int k = freqs[j]; k>=1; --k) res /= k;
            // }
    
            // return res;