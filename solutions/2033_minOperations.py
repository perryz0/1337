# Mar. 25th, 2025 (daily)

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        r = grid[0][0]%x
        vals = []
        m,n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if r != grid[i][j]%x:
                    return -1
                vals.append(grid[i][j])

        vals.sort()

        med = vals[(m*n-1)//2]

        return sum(abs(val - med) for val in vals)//x
    