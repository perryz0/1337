# Mar. 13th, 2025 (daily)

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        candies.sort()
        n = len(candies)

        #binsearch
        l,r = 1,max(candies)
        ans = 0

        while l <= r:
            mid = (l+r)//2

            count = sum(c//mid for c in candies)

            if count >= k:
                ans = mid
                l = mid+1
            else:
                r = mid-1

        return ans