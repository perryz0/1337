# Mar. 5th, 2025 (daily)

class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        res = []
        s = set()
        for row in grid:
            for e in row:
                if e in s:
                    res.append(e)
                s.add(e)

        m = pow(len(grid), 2)
        for i in range(1, m+1):
            if i not in s:
                res.append(i)

        return res
