// July 27th, 2025

class Solution {
private:
    int n, MAXOR;
    vector<int> numbers;
    int ans;

    void backtrack(int curr, int idx) {
        if (curr == MAXOR) {
            ++ans;
        }

        for (int i=idx+1; i<n; ++i) {
            int newCurr = curr | numbers[i];
            backtrack(newCurr, i);
        }
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        // first find the maxOR
        MAXOR=0;
        numbers=nums;
        for (const int& num : nums) MAXOR |= num;

        // choose not choose
        n=nums.size();
        ans=0;
        for (int i=0; i<n; ++i) {
            backtrack(nums[i], i);
        }

        return ans;
    }
};