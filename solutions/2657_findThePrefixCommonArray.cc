// Jan. 13th, 2025 (daily)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size());
        vector<int> freqs(A.size()+1);
        int runningCnt = 0;
        for (int i = 0; i < A.size(); ++i) {
            freqs[A[i]]++;
            freqs[B[i]]++;
            runningCnt += (freqs[A[i]] == 2) ? 1 : 0;
            runningCnt += (freqs[B[i]] == 2) ? 1 : 0;
            if (A[i] == B[i]) runningCnt--;
            res[i] = runningCnt;
        }
        return res;
    }
};


        // o(n^2)
        // vector<int> res(A.size());
        // unordered_set<int> A_elems(A.size());
        // for (int i = 0; i < A.size(); ++i) {
        //     A_elems.insert(A[i]);
        //     int cnt = 0;
        //     for (int j = 0; j <= i; ++j) if (A_elems.find(B[j]) != A_elems.end()) cnt++;
        //     res[i] = cnt;
        // }
        // return res;