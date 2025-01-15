// Jan. 14th, 2025 (daily)

class Solution {
public:
    int minimizeXor(int num1, int num2) {

        unsigned int x = num1; unsigned int y = num2;
        int oneCnt = 0;

        while (y != 0) {
            if (y & 1) oneCnt++;
            y = y >> 1;
        }

        unsigned int res = 0;

        for (int i = 31; i >= 0; --i) {
            if (oneCnt == 0) break;
            if (x & (1 << i)) { oneCnt--; res |= 1 << i; }
        }

        int bitpos = 0;
        while (oneCnt != 0) {
            if (!(res & (1 << bitpos))) { res |= 1 << bitpos; oneCnt--; }
            bitpos++;
        }

        return res;
    }
};