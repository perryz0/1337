// May 10th, 2025 (daily)

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int& n : arr) {
            if (n%2 == 1) cnt++;
            else cnt = 0;
            if (cnt == 3) return true;
        }
        return false;
    }
};