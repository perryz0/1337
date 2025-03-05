# Mar. 4th, 2025 (daily)

class Solution:
    def coloredCells(self, n: int) -> int:
        # res = 1, 5, 13, 25
        # n = 1, 2, 3, 4
        # f(n) = n^2 + (n-1)^2
        # f(1) = 1 = 1 + 0^2
        # f(2) = 5 = 2^2 + 1^2
        # f(3) = 13 = 3^2 + 2^2
        return pow(n,2)+pow(n-1,2)
