# Mar. 26th, 2025 (daily)

class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        freqs = defaultdict(int)
        for num in nums:
            freqs[num] += 1

        dom, maxfreq = 0, 0

        for k in freqs:
            if freqs[k] > maxfreq:
                maxfreq = freqs[k]
                dom = k

        n = len(nums)
        # print(f"dom is {dom}, maxfreq is {maxfreq}")
        f1, f2 = 0, maxfreq
        for i in range(n):
            if nums[i] == dom:
                # print(f"changing frequencies!")
                f1 += 1
                f2 -= 1
                # print(f"iter is {i}, f1: {f1}, f2: {f2}")

            # print(f"{f1} > {(i+1)//2}? {f2} > {(n-(i+1))//2}?")
            if f1 > (i+1)//2 and f2 > (n-(i+1))//2:
                return i

        return -1