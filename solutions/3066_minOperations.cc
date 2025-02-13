// Feb. 12th, 2025 (daily)

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> pq;
    
            for (int& num : nums) pq.push(num);
    
            long long currMin = pq.top();
            int cnt = 0;
            long long x = 0, y = 0;
            while (currMin < k && !pq.empty()) {
                x = pq.top(); pq.pop();
                y = pq.top(); pq.pop();
                pq.push(min(x,y)*2+max(x,y));
                currMin = pq.top();
                cnt++;
            }
    
            return cnt;
        }
    };