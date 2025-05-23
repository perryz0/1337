// May 14th, 2025 (daily)

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();

        sort(queries.begin(), queries.end());

        priority_queue<int> pq;
        vector<int> delta(n + 1, 0);
        int ops = 0, j = 0;

        for (int i = 0; i < n; ++i) {
            ops += delta[i];
            while (j < q && queries[j][0] == i) {
                pq.push(queries[j][1]);
                ++j;
            }

            while (ops < nums[i] && !pq.empty() && pq.top() >= i) {
                ++ops;
                if (pq.top() + 1 < n)
                    delta[pq.top() + 1] -= 1;
                pq.pop();
            }

            if (ops < nums[i]) return -1;
        }

        return pq.size();
    }
};
