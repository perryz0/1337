# Apr. 8th, 2025 (daily)

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        if min(nums) < k:
            return -1

        s = set()
        for n in nums:
            s.add(n)

        return len(s) if k < min(nums) else len(s)-1