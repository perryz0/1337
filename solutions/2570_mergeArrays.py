# Mar. 1st, 2025 (daily)

class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        res = []
        sz1, sz2 = len(nums1), len(nums2)
        n1, n2 = 0, 0
        while (n1 < sz1 and n2 < sz2):
            first = nums1[n1]
            second = nums2[n2]
            if (first[0] == second[0]):
                res.append([first[0], first[1]+second[1]])
                n1+=1
                n2+=1
            elif (first[0] < second[0]):
                res.append(first)
                n1+=1
            else:
                res.append(second)
                n2+=1

        while (n1 < sz1):
            res.append(nums1[n1])
            n1+=1

        while (n2 < sz2):
            res.append(nums2[n2])
            n2+=1

        return res