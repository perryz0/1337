class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        letters = ['a', 'b', 'c']
        happys = []

        def backtrack(curr, idx):
            if (len(curr) == n):
                happys.append(curr)
                return
            for i in range(len(letters)):
                if (i == idx):
                    continue
                backtrack(curr + letters[i], i)

        for i in range(len(letters)):
            backtrack(letters[i], i)

        return "" if k-1 >= len(happys) else happys[k-1]
