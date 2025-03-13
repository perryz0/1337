# Mar. 12th, 2025 (daily)

class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        q = len(queries)

        # check if curr amount of queries give valid zero arr, o(n)
        def valid(k):
            z = [0]*(n+1)

            for i in range(k):
                l,r,v = queries[i]
                z[l]+=v
                z[r+1]-=v

            curr = 0
            for i in range(n):
                curr += z[i]
                if nums[i] > curr:
                    return False
            return True

        # bin search on queries to find k, o(logq)
        l,r=0,q+1

        while l < r:

            mid = (l+r) // 2
            if valid(mid):
                r = mid
            else:
                l = mid+1
            
        return l if l!=q+1 else -1
