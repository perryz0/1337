// June 12th, 2025 (daily)

class Solution {
private:
    int n;
    vector<int> ar;

    int valid(const int& g) {
        int pcnt=0;
        for (int i=0; i<n-1; ++i) {
            if (ar[i+1]-ar[i] <= g) {
                pcnt++;
                i++; // skip extra idx
            }
        }

        return pcnt;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        ar=nums;
        n=nums.size();
        int l=0, r=nums[n-1];

        // binsearch on gap candidate (g), until >=2p values in the lower bound
        while (l<r) {
            int m = l+(r-l)/2;
            if (valid(m) >= p) {
                r=m;
            }
            else {
                l=m+1;
            }
        }

        return l;
    }
};