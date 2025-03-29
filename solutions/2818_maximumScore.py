# Mar. 28th, 2025 (daily)

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        N = len(nums)
        MOD = pow(10,9)+7
        res = 1

        scores = []
        for num in nums:
            s = 0
            n=num
            for f in range(2, int(sqrt(n))+1):
                if not n%f:
                    s += 1
                    while not n%f:
                        n = n // f
            
            if n>=2:
                s += 1
            scores.append(s)

        # print(scores)

        left = [-1]*N
        # print(left)
        # return
        right = [N]*N
        stk = []
        for i,s in enumerate(scores):
            while stk and scores[stk[-1]]<s:
                idx = stk.pop()
                right[idx] = i
            if stk:
                left[i] = stk[-1]
            stk.append(i)

        h = [(-n,i) for i,n in enumerate(nums)]
        heapq.heapify(h)

        while k>0:
            n,idx = heapq.heappop(h)
            n = -n
            s = scores[idx]

            lcnt = idx-left[idx]
            rcnt = right[idx]-idx
            
            cnt = lcnt*rcnt
            ops = min(cnt,k)
            res = (res*pow(n,ops,MOD))%MOD
            k -= ops
        
        return res