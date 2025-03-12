# Mar. 11th, 2025 (daily)

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        def firstFirstPos():
            l,r = 0,len(nums)
            while l < r:
                mid = (l+r) // 2
                if nums[mid] > 0:
                    r = mid
                else:
                    l = mid + 1
            return l

        def findLastNeg():
            l, r = 0, len(nums)
            while l < r:
                mid = (l + r) // 2
                if nums[mid] < 0:
                    l = mid + 1
                else:
                    r = mid
            return l

        n = findLastNeg()
        p = len(nums)-firstFirstPos()
        return max(n,p)




        # #o(logn): find the smallest abs(val), or 0

        # l,r=0,len(nums)-1
        # curr = 2000
        # idx=-1

        # while l<r:
        #     mid = (l+(r-l))/2
        #     if nums[mid] == 0:
        #         curr = 0
        #         idx = mid
        #         break
        #     if abs(nums[mid]) < curr:
        #         if nums[mid] > 0:
        #             r = mid
        #         elif nums[mid] < 0:
        #             l = mid
        #         idx = mid
        #         curr = abs(nums[mid])
        
        # if curr == 0:
        #     # expand and count 0's
        #     # cnt = 1
        #     for i in range(idx+1, len(nums)):
        #         curr = nums[i]
        #         if curr != 0:
        #             pidx = i
            
        #     for i in range(idx-1, -1, -1):
        #         curr = nums[i]
        #         if curr != 0:
        #             nidx = i

        #     return max(nidx+1, len(nums)-pidx)
        
        # elif curr > 0:
        #     return max(idx, len(nums)-idx)
        
        # else:
        #     return max(idx+1, len(nums)-idx-1)

        #o(n)
        # p,n=0,0
        # for num in nums:
        #     if num > 0:
        #         p+=1
        #     elif num < 0:
        #         n+=1

        # return max(p,n)