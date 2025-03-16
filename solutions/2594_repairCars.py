# Mar. 14th, 2025 (daily)

class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:

        def valid(time):
            total=0
            for rank in ranks:
                total+=floor(sqrt(time//rank))
                if total >= cars:
                    return True
            return False

        l,r = 1, min(ranks)*pow(cars,2)
        while l<r:
            mid = (l+r)//2
            if valid(mid):
                r = mid
            else:
                l = mid+1

        return l