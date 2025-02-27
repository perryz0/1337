// Feb. 26th, 2025 (daily)

class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int maxLen = 0;
            for (int i = 0; i<arr.size(); ++i) {
                for (int j = i+1; j<arr.size(); ++j) {
                    for (int k = j+1; k<arr.size(); ++k) {
                        if (arr[k]<arr[i]+arr[j]) continue;
                        else if (arr[k]==arr[i]+arr[j]) {
                            int curr = 3;
                            fib(j, k, arr, curr);
                            maxLen = max(maxLen, curr);
                        }
                        else break;
                    }
                }
            }
    
            return maxLen;
        }
    
        void fib(int& prev, int& curr, vector<int>& arr, int& currLength) {
            if (curr == arr.size()) return;
    
            for (int i = curr+1; i<arr.size(); ++i) {
                if (arr[i] < arr[prev]+arr[curr]) continue;
                else if (arr[i] == arr[prev]+arr[curr]) {
                    currLength++;
                    fib(curr, i, arr, currLength);
                }
                else break;
            }
    
            return;
        }
    };