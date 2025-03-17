# Mar. 16th, 2025 (daily)

class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        freqs = defaultdict(int)
        for num in nums:
            freqs[num] += 1

        for num in freqs:
            if freqs[num]%2 == 1:
                return False

        return True