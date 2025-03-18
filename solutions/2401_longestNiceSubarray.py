# Mar. 17th, 2025 (daily)

class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        l,r = 0,1
        n = len(nums)

        res = 1

        curr = 1
        runningOR = nums[l]
        while r < n:

            while (runningOR & nums[r]) != 0:
                runningOR ^= nums[l]
                l += 1
                curr -= 1

            curr += 1
            runningOR |= nums[r]
            res = max(res, curr)
            r+=1

        return res



# o(n)
# class Solution:
#     def longestNiceSubarray(self, nums: List[int]) -> int:
#         l,r = 0,1
#         n = len(nums)
#         res = 1

#         curr = 1
#         while r < n:

#             for i in range(l,r):
#                 if nums[i] & nums[r] != 0:
#                     l = r
#                     curr = 0
#             # if nums[l] & nums[r] != 0:
#             #     l = r
#             #     curr = 1
#             curr += 1

#             res = max(res, curr)
#             print("num is " + str(nums[r]))
#             print("res is " + str(res))
#             print("curr is " + str(curr))
#             r+=1

#         return res