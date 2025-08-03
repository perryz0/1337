// Aug 2nd, 2025

class Solution {
private:
    int s;
    vector<vector<int>>* f;

    int check(int l, int r) {
        int x = (*f)[l][0], y = (*f)[r][0];
        if (y <= s) return s - x;
        if (x >= s) return y - s;
        return min(abs(s-y), abs(s-x)) + (y-x);
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruitList, int start, int maxSteps) {
        s = start;
        f = &fruitList;

        int l=0, r=0;
        int n = fruitList.size();
        int sum=0, ans=0;
        while (r < n) {
            sum += (*f)[r][1];
            while (l <= r && check(l,r) > maxSteps) sum -= (*f)[l++][1];
            ans = max(ans,sum);
            ++r;
        }
        return ans;
    }
};
