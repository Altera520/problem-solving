from collections import deque

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        q = deque()
        visit = {}

        directions = [
            (0, -1), # left
            (0, 1),  # right
            (-1, 0), # up
            (1, 0),  # down
        ]

        y_sz = len(grid)
        x_sz = len(grid[0])

        for y in range(0, y_sz):
            for x in range(0, x_sz):
                if grid[y][x] == 0 or (y, x) in visit:
                    continue

                cnt = 0
                q.append((y, x))
                visit[(y, x)] = True
                while q:
                    curr_y, curr_x = q.popleft()
                    cnt += 1

                    for d in directions:
                        next_y = curr_y + d[0]
                        next_x = curr_x + d[1]

                        if not (0 <= next_y < y_sz):
                            continue
                        if not (0 <= next_x < x_sz):
                            continue
                        if grid[next_y][next_x] == 0:
                            continue
                        if (next_y, next_x) in visit:
                            continue
                        q.append((next_y, next_x))
                        visit[(next_y, next_x)] = True

                ans = max(ans, cnt)
        return ans
