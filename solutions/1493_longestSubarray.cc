// Aug. 23rd, 2025

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lastZero=-1;
        int prevSegment=0;
        int N=nums.size();
        for (int i=0; i<N; ++i) {
            if (nums[i]==0) {
                lastZero=i;
                break;
            }
            prevSegment++;
        }

        int ans=0;
        int START=lastZero;
        for (int i=START+1; i<N; ++i) {
            if (nums[i]==0) {
                int currSegment=i-lastZero-1;
                // cout << "prev: " << prevSegment << ", curr: " << currSegment << endl;
                ans=max(prevSegment+currSegment, ans);
                prevSegment=currSegment;
                lastZero=i;
            }
        }

        int currSegment=N-lastZero-1;
        ans=max(prevSegment+currSegment, ans);
        prevSegment=currSegment;

        return (lastZero == -1) ? N-1 : ans;
    }
};