# Mar. 3rd, 2025 (daily)

class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while (n>0):
            if (n%3==2):
                return False
            n//=3

        return True

        # "hardcoded method"
        # powers = 16
        # while powers >= 0:
        #     toSub = pow(3, powers)
        #     if (toSub <= n):
        #         n -= pow(3, powers)
        #     powers -= 1

        # return False if (n != 0) else True