# Sep. 14th, 2025

class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ans = 0
        charset = set(brokenLetters)
        words = text.split(" ")
        for w in words:
            valid = True
            for c in charset:
                if c in w:
                    valid = False
                    break
            if valid:
                ans += 1

        return ans