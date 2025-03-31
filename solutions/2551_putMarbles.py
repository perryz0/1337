# Mar. 30th, 2025 (daily)

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        # sorting approach
        if k == 1:
            return 0

        sums = [x+y for x,y in pairwise(weights)]

        return sum(nlargest(k-1,sums)) - sum(nsmallest(k-1,sums))



        # # two topk's
        # mini = []
        # maxi = []

        # for x,y in pairwise(weights):
        #     summ = x+y
            
        #     heapq.heappush(mini, -summ)
        #     heapq.heappush(maxi, summ)

        #     while len(mini) > k-1:
        #         heapq.heappop(mini)
        #     while len(maxi) > k-1:
        #         heapq.heappop(maxi)

        # return sum(maxi) + sum(mini)    # reverse the neg