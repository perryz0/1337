// Jan. 1st, 2025 (daily)

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for (int& num : nums) sum += num;

        int cnt = 0;

        long long runningSum = 0;
        int iterator = 0;
        for (int& num : nums) {
            runningSum += num;
            sum -= num;
            if (runningSum >= sum) {
                if (sum != 0) cnt++;
                else if (sum == 0 && iterator != nums.size()-1) cnt++;
            }
            iterator++;
        }

        return cnt;
    }
};