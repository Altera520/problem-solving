from collections import deque

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        d = [(-1, 0), (0, -1)]
        memo = [[0 for _ in range(n)] for _ in range(m)]
        visit = [[False for _ in range(n)] for _ in range(m)]
        memo[m - 1][n - 1] = 1
        
        def bfs(pt):
            q = deque([pt])
            while q:
                y, x = q.popleft()
                for dy, dx in d:
                    ny = y + dy
                    nx = x + dx
                    if not (0 <= ny < m and 0 <= nx < n):
                        continue
                    memo[ny][nx] += memo[y][x]
                    if visit[ny][nx]:
                        continue
                    q.append((ny, nx))
                    visit[ny][nx] = True
        
        bfs((m - 1, n - 1))
        return memo[0][0]
            
