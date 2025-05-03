// May 2nd, 2025 (daily)

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> t;
        unordered_map<int,int> b;

        for (int& v : tops) t[v]++;
        for (int& v : bottoms) b[v]++;

        int mx=0, target=-1;
        for (auto& [val, freq] : t) {
            if (freq > mx) {
                target = val;
                mx = freq;
            }
        }

        int n = tops.size();

        int bcnt=0, tcnt=0;
        for (int i=0; i<n; ++i) {
            if (tops[i] != target && bottoms[i] == target) {
                tops[i] = target;
                tcnt++;
            }
            else if (bottoms[i] != target && tops[i] == target) {
                bottoms[i] = target;
                bcnt++;
            }
        }

        for (int i=0; i<n; ++i) {
            if (tops[i] != target) return -1;
        }

        return min(bcnt,tcnt);
    }
};