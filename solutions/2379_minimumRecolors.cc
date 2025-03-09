// Mar. 7th, 2025 (daily)

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int wcnt = 0;
            int minChanges = k;
    
            // init window
            for (int i = 0; i<k; ++i) {
                if (blocks[i] == 'W') wcnt++;
            }
    
            minChanges = wcnt;
    
            for (int i = k; i<blocks.size(); ++i) {
                if (blocks[i] == 'W') wcnt++;
                if (blocks[i-k] == 'W') wcnt--;
    
                minChanges = min(minChanges, wcnt);
            }
    
            return minChanges;
        }
    };