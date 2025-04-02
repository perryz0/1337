# Apr. 1st, 2025 (daily)

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        # o(n) pre-suffix max
        lmax = [0]*n
        for i in range(1,n):
            lmax[i] = max(lmax[i-1],nums[i-1])

        rmax = [0]*n
        for i in reversed(range(n-1)):
            rmax[i] = max(rmax[i+1],nums[i+1])

        ans=0
        for i in range(1,n-1):
            ans = max(ans, (lmax[i]-nums[i])*rmax[i])

        return ans

        # naive o(n^3)
        # res = 0
        # for i in range(n):
        #     for j in range(i+1,n):
        #         for k in range(j+1,n):
        #             res = max(res, (nums[i]-nums[j])*nums[k])

        # return res