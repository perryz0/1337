// Mar. 10th, 2025 (daily)

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        l,r = 0,0
        abc = defaultdict(int)
        cnt = 0

        for r in range(len(s)):
            abc[s[r]]+=1

            while abc['a'] >= 1 and abc['b'] >= 1 and abc['c'] >= 1:
                cnt += (len(s)-r)
                abc[s[l]]-=1
                l+=1

        return cnt