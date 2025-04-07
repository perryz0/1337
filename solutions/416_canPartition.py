# Apr. 6th, 2025 (daily)

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total%2 == 1:
            return False
        
        target = sum(nums)//2
        
        # 0/1 knapsack
        dp = [False]*(target+1)
        dp[0] = True

        for num in nums:
            for tar in reversed(range(num,target+1)):
                dp[tar] = dp[tar] or dp[tar-num]

        return dp[target]
