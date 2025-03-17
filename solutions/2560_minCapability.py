# Mar. 14th, 2025 (daily)

class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def valid(capability):
            cnt = 0
            i = 0
            while i < len(nums):
                if nums[i]<=capability:
                    cnt+=1
                    i+=1
                i+=1
            return cnt>=k

        lo, hi = min(nums),max(nums)
        while lo < hi:
            mid = (lo+hi)//2
            if valid(mid):
                hi = mid
            else:
                lo = mid+1

        return lo