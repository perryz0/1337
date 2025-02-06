// Feb. 5th, 2025 (daily)

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;

        unordered_map<int, int> prods;

        for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) prods[nums[i]*nums[j]]++;

        int cnt = 0;
        long long inc;

        // (x choose 2) * 8
        for (auto& [x, y] : prods) {
            inc = 1;
            for (int i = y; i >= 2; --i) inc *= i;
            for (int i = y; i > 2; --i) inc /= i-2;
            cnt += (inc == 1) ? 0 : (inc * 4);  // div 2, mult 8
        }

        return cnt;
    }
};