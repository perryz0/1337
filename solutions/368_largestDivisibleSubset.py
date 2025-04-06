# Apr. 5th, 2025 (daily)

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        dp = {}

        # print(nums)

        def bt(idx, p):
            if idx == len(nums):
                return []
            if (idx,p) in dp:
                return dp[(idx,p)]

            res = bt(idx+1,p)
            if nums[idx]%p == 0:
                t = [nums[idx]] + bt(idx+1, nums[idx])
                res = t if len(t) > len(res) else res

            dp[(idx,p)] = res
            return res

        return bt(0,1)
