# Apr. 4th, 2025 (daily)

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        rsum = 0
        def bt(idx, rxor):
            nonlocal nums,n,rsum
            # print(f"rsum is currently {rsum}")
            # print(f"adding {rxor}")
            rsum += rxor
            for i in range(idx, n-1):
                # rxor^=nums[idx+1]
                bt(i+1, rxor^nums[i+1])
                print(rxor^nums[i+1])
                

        for i in range(n):
            bt(i, nums[i])
        
        return rsum
