// Oct. 13th, 2025

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k==1) return true;
        int cnt1=1, n=nums.size();
        for (int r1=1; r1 < n; ++r1) {
            // cout << nums[r1] << endl;
            if (nums[r1]>nums[r1-1]) ++cnt1;
            // now check if prev window is k-sized
            else {
                if (cnt1 >= k) {
                    // expand the next window
                    int cnt2 = 1;
                    int r2=r1+1;
                    while (r2 < n && nums[r2] > nums[r2-1]){
                        // cout << nums[r2] << endl;
                        ++r2;
                        ++cnt2;
                    }
                    // cout << cnt2 << endl;
                    if (cnt2 >= k) return true;
                }
                cnt1=1;
            }
            // cout << "cnt1 is:" << cnt1 << endl;
            if (cnt1 == k*2) return true;
        }

        return false;
    }
};




