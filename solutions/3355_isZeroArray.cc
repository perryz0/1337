// May 19th, 2025 (daily)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // sort(queries.begin(), queries.end());
        vector<int> diff(n+2, 0);
        for (auto& q : queries) {
            diff[q[0]+1]++;
            diff[q[1]+2]--;
        }

        // vector<int> ps(n, 0);
        // ps[0] = diff[2];
        for (int i=2; i<n+2; ++i) {
            diff[i] += diff[i-1];
            // ps[i-2] = ps[i-3] + diff[i-1];
        }

        // for (int& d : diff) cout << d << endl;

        for (int i=0; i<n; ++i) if (nums[i] > diff[i+1]) return false;

        // for (int& p : ps) cout << p << endl;

        return true;
    }
};