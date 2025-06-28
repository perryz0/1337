// June 27th, 2025

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;   // val, idx
        for (int i=0; i<nums.size(); ++i) {
            pq.push({nums[i], i});
        }

        vector<pair<int,int>> vals;
        for (int i=0; i<k; ++i) {
            vals.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }

        sort(vals.begin(), vals.end());

        vector<int> ans;
        for (auto [i, v] : vals) {
            ans.push_back(v);
        }

        return ans;
    }
};