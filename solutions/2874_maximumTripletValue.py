# Apr. 2nd, 2025 (daily)

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        # #o(n) time, o(1) space (failed)
        # pm,sm = 0,nums[n-1]
        # ans=0
        # for i in range(1,n-1):
        #     ans=max(ans, (pm-nums[i])*sm)
        #     pm = max(pm, nums[i])
        #     sm = max(sm, nums[n-i-1])

        # return ans


        #o(n) time pre/suffix max, o(n) space
        pm = [0]*n
        sm = [0]*n
        for i in range(1,n):
            pm[i] = max(pm[i-1], nums[i-1])
            sm[n-i-1] = max(sm[n-i], nums[n-i])

        # print(pm)
        # print(sm)

        ans=0
        for i in range(1,n-1):
            ans=max(ans, (pm[i]-nums[i])*sm[i])

        return ans