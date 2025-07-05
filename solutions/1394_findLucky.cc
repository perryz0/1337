// July 4th, 2025 (!!!)

class Solution {
private:
    int freqs[501];

public:
    int findLucky(vector<int>& arr) {
        // int freqs[501];
        memset(freqs, 0, 501);
        for (const int& n : arr) freqs[n]++;
        for (int i=500; i>=1; --i) if (i==freqs[i]) return i;

        return -1;

        // unordered_map<int,int> freqs;
        // for (const int& n : arr) freqs[n]++;

        // int MAX=-1;
        // for (const int& n : arr) {
        //     if (freqs[n] == n) {
        //         MAX=max(MAX, n);
        //     }
        // }

        // return MAX;
    }
};
