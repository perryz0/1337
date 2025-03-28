# Mar. 27th, 2025 (daily)

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m,n = len(grid), len(grid[0])
        k = len(queries)

        sorted_q = sorted(set(queries))
        visited = [[False] * n for _ in range(m)]
        heap = [(grid[0][0], 0, 0)]
        visited[0][0] = True

        # multi stage bfs? modified dijk kinda

        qdict = defaultdict(int)
        points, idx = 0,0

        dirs = [(0,1),(0,-1),(1,0),(-1,0)]

        for q in sorted_q:
            while heap and heap[0][0] < q:
                val, x, y = heapq.heappop(heap)
                points += 1
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                        visited[nx][ny] = True
                        heapq.heappush(heap, (grid[nx][ny], nx, ny))
            qdict[q] = points

        return [qdict[q] for q in queries]

        # qdict = defaultdict(int)
        # ptr = 0
        # runningCnt = 0
        # ans = []
        # q = deque()
        # q.append((0,0))

        # dirs = [(0,1),(0,-1),(1,0),(-1,0)]

        # while q:
        #     cx,cy = q[0]
        #     q.popleft()
        #     runningCnt += 1
        #     # if grid[cx][cy] > copy[ptr]:
        #         # runningCnt += 1
        #     # else:
        #         # q.append((cx,cy))   # should reprocess for a future dir move

        #     cache = []
        #     for dx,dy in dirs:
        #         nx,ny = cx+dx, cy+dy
        #         if 0 <= nx < m and 0 <= ny < n:
        #             cache.append((grid[nx][ny],nx,ny))
        #             if grid[nx][ny] > copy[ptr]:
        #                 cache.popleft()
        #                 q.append((nx,ny))
        #         heapq.heapify(cache)

        #     # when the q is empty, we start incrementing the ptr, gotta still have candidates
        #     while not q and cache and ptr < k-1:
        #         qdict[copy[ptr]] = runningCnt
        #         ptr += 1
        #         p, nx, ny = cache[0]
        #         if copy[ptr] > p:
        #             q.append((nx,ny))
        #             break

        # for q in queries:
        #     ans.append(qdict[q])

        # return ans