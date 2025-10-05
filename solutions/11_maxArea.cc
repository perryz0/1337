// Oct. 3rd, 2025

class Solution {
public:
    int maxArea(vector<int>& height) {
        // fix the right ptr
        int L=0, n=height.size();
        int R=n-1;
        int ans=0;
        while (L<R) {
            ans=max(ans, min(height[L],height[R])*(R-L));
            if(height[L]<height[R]) L++;
            else R--;
        }
        return ans;
    }
};