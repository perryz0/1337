# Apr. 7th, 2025 (daily)

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        if len(nums) == len(set(nums)):
            return 0

        cnt = 0
        
        while len(nums) > 0:
            nums = nums[3:]
            cnt += 1

            if len(nums) == len(set(nums)):
                return cnt
        
        return cnt
    