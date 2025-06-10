// June 8th, 2025 (daily)
//(revisit)

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            int steps = count(n, cur, cur + 1);
            if (steps <= k) cur++, k -= steps;
            else cur *= 10, --k;
        }
        return cur;
    }

private:
    int count(int n, long a, long b) {
        int res = 0;
        while (a <= n) {
            res += min((long)n + 1, b) - a;
            a *= 10, b *= 10;
        }
        return res;
    }
};
