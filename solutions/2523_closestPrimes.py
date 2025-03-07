# Mar. 6th, 2025 (daily)

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:

        def soe(left, right):
            if left < 2:
                left = 2

            primes = [True] * (right - left + 1)

            for i in range(2, int(right**0.5) + 1):
                start = max(i * i, (left + i - 1) // i * i)
                for j in range(start, right + 1, i):
                    primes[j - left] = False

            return [i for i, is_prime in enumerate(primes, start=left) if is_prime]


        primes = soe(left, right)

        res = [-1, -1]
        if len(primes) < 2:
            return res

        prev, curr = primes[0], primes[1]
        res = [prev, curr]
        gap = curr-prev
        for i in range(2, len(primes)):
            if gap <= 2:
                return res  # twin primes early exit

            prev = curr
            curr = primes[i]
            if curr-prev < gap:
                gap = curr-prev
                res = [prev, curr]

        return res