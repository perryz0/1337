// Sep. 30th, 2025

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int empty=0;
        // numBottles = filled, empty = not filled
        while (numBottles+empty >= numExchange) {
            // int newEmpty = numBottles;
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
            if (empty >= numExchange) {
                numBottles += empty/numExchange;    // refilling
                empty %= numExchange;
                // cout << "after refill: " << numBottles << ", remaining empty: " << empty << endl;
            }
            // cout << "numBottles: " << numBottles << ", newEmpty: " << newEmpty << ", currEmpty: " << empty << endl;
            // cout << "ans: " << ans << endl;
            // cout << "--------------" << endl;
        }

        return ans+numBottles;  // LAST BATCH
    }
};