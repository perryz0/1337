// Apr. 29th, 2025 (daily)

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int cnt = 0;
    
            for (int& n: nums) {
                if (to_string(n).length() % 2 == 0) cnt++;
            }
    
            return cnt;
        }
    };