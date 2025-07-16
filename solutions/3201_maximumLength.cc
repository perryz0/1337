// July 15th, 2025

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // int ans=0;
        int n=nums.size();
        // e+e=e, e+o=o, o+e=o, o+o=e
        // case1: start with e+e, o+o
        int oddCnt=0, evenCnt=0;
        for (int i=0; i<n; ++i) {
            if (nums[i]%2==0) evenCnt++;
            else oddCnt++;
        }
        int ans=max(oddCnt, evenCnt);

        // case2: alternating
        int startE=0, startO=0; // start*=prev
        for (int i=0; i<n; ++i) {
            if (nums[i]%2==0){
                startE=i;
                break;
            } 
        }

        int cnt=1;
        bool odd=true;
        // case2a: start with even, so first thing is to look for odd
        for (int i=startE+1; i<n; ++i) {
            if (nums[i]%2==odd) {
                cnt++;
                odd = !odd;
            }
        }

        ans=max(ans,cnt);

        for (int i=0; i<n; ++i) {
            if (nums[i]%2==1){
                startO=i;
                break;
            } 
        }

        cnt=1;
        odd=false;
        // case2b: start with odd, so first thing is to look for even
        for (int i=startO+1; i<n; ++i) {
            if (nums[i]%2==odd) {
                cnt++;
                odd = !odd;
            }
        }

        return max(ans,cnt);
    }
};