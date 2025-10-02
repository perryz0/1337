// Oct. 1st, 2025

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        int empty=0;
        while (numBottles+empty >= numExchange) {
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
            if (empty >= numExchange) {
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
        }

        return ans+numBottles;
    }
};