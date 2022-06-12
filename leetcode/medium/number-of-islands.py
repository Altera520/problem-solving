from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        
        m = len(grid)
        n = len(grid[0])
        visit = [[False for _ in range(n)] for _ in range(m)]
        is_in = lambda y, x: 0 <= y < m and 0 <= x < n
        
        def bfs(y, x):
            q = deque([(y, x)])
            visit[y][x] = True
            
            while q:
                cy, cx = q.popleft()
                for dy, dx in d:
                    ny = cy + dy 
                    nx = cx + dx
                    if not is_in(ny, nx):
                        continue
                    if visit[ny][nx]:
                        continue
                    if grid[ny][nx] == '0':
                        continue
                    q.append((ny, nx))
                    visit[ny][nx] = True
        
        ans = 0
        for y in range(m):
            for x in range(n):
                if grid[y][x] == '1' and not visit[y][x]:
                    bfs(y, x)
                    ans += 1
        return ans
                
