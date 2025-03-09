// Mar. 8th, 2025 (daily)

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int cnt = 0, alternatingCount = 1;
    
            for (int i = 1; i < k; ++i) {
                if (colors[i] != colors[i-1]) alternatingCount++;
            }
            if (alternatingCount == k) cnt++;
    
            for (int i = k; i < n+k-1; ++i) {
                int slotOut = (i-k) % n;
                int slotIn = i % n;
    
                if (colors[slotOut] != colors[(slotOut+1) % n]) alternatingCount--;
                if (colors[slotIn] != colors[(slotIn-1+n) % n]) alternatingCount++;
    
                if (alternatingCount == k) cnt++;
            }
    
            return cnt;
        }
    };
    