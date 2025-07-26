from collections import deque

class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        precision = 4

        ans = 0
        sz = len(grid)
        psz = sz * precision

        m = [[0 for _ in range(psz)] for _ in range(psz)]

        def init(y, x):
            ch = grid[y][x]
            st_y = y * precision 
            st_x = x * precision

            if ch == '\\':
                for i, py in enumerate(range(st_y, st_y + precision)):   
                    for j, px in enumerate(range(st_x, st_x + precision)):
                        if i == j:
                            m[py][px] = 1
                            break
            elif ch == '/':
                for i, py in enumerate(range(st_y, st_y + precision)):   
                    for j, px in enumerate(range(st_x + precision - 1, st_x - 1, -1)):
                        if i == j:
                            m[py][px] = 1
                            break
            else:
                ...

        for y in range(sz):
            for x in range(sz):
                init(y, x)

        # for row in m:
        #     print(' '.join([str(r) for r in row]))

        q = deque()
        directions = [
            (0, 1),
            (0, -1),
            (1, 0),
            (-1, 0),
        ]

        for y in range(psz):
            for x in range(psz):
                start = (y, x)
                if m[y][x] == 1:
                    continue

                q.append(start)
                m[y][x] = 1

                while q:
                    curr_y, curr_x = q.popleft()

                    for dy, dx in directions:
                        next_y = curr_y + dy
                        next_x = curr_x + dx
                        _next = (next_y, next_x)

                        if not (0 <= next_y < psz and 0 <= next_x < psz):
                            continue
                        if m[next_y][next_x] == 1:
                            continue
                        
                        q.append(_next)
                        m[next_y][next_x] = 1
                ans += 1

        return ans
