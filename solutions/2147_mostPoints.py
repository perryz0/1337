# Mar. 31st, 2025 (daily)

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        # pts = [q[0] for q in questions]
        n = len(questions)
        pts = [0]*n
        pts[n-1] = questions[n-1][0]
        # res[0]*n

        for i in reversed(range(n-1)):
            p,b = questions[i]
            pts[i] = p

            if b+i+1 < n:
                pts[i] = max(pts[i], p + pts[b+i+1])

            pts[i] = max(pts[i], pts[i+1])
        
        return pts[0]

        # print(pts)

        # if n == 1:
        #     return pts[0]

        # for i in range(1, n):
        #     print(f"iter is {i}")
        #     # print(f"pos is {questions[i][1]+i+1}")
        #     if questions[i-1][1]+i < n:
        #         print(f"{pts[i-1]} vs. {questions[i-1][1]+i}")
        #         pts[i] = max(pts[i], pts[i-1]+pts[questions[i-1][1]+i])
        #     else:
        #         pts[i] = max(pts[i], pts[i-1])
        #     print(f"curr pts is {pts[i]}")

        # return pts[n-1]