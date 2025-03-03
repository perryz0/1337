
# Mar. 2nd, 2025 (daily)

class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        #three pass one liner
        return [x for x in nums if x < pivot] + [x for x in nums if x == pivot] + [x for x in nums if x > pivot]

        #one pass
        # less = []
        # g = []
        # eq = []
        # for i,val in enumerate(nums):
        #     if (val < pivot):
        #         less.append(val)
        #     elif val > pivot:
        #         g.append(val)
        #     else:
        #         eq.append(val)

        # return less+eq+g
            