// Jan. 16th, 2025 (daily)

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        bool runningXOR = 0;
        for (int& bit : derived) runningXOR ^= bit;

        return !runningXOR;
    }
};