# Mar. 29th, 2025 (daily)

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # shitty o(n) brute force
        tables = []

        def merge(idx, tables):
            for i in reversed(range(idx+1, len(tables))):
                tables[idx].update(tables[i])
                tables.pop(i)

        for c in s:
            flag = False
            for i, t in enumerate(tables):
                if c in t:
                    flag = True
                    if i != len(tables)-1:
                        merge(i, tables)
                    tables[i].add(c)
                    break
            
            if not flag:
                # create new set and append to tables
                tables.append(set(c))
        
        cnt = 0
        it = 0
        res = []
        for c in s:
            if c in tables[it]:
                cnt += 1
            else:
                it += 1
                res.append(cnt)
                cnt = 1

        # dont forget last running cnt
        res.append(cnt)
        
        return res