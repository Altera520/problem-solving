from collections import deque, defaultdict

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        d = [(-1, 0), (0, -1)]
        start = (n - 1, m - 1)
        end = (0, 0)
        q = deque([start])
        
        memo = defaultdict(int)
        memo[start] = 1
        
        while q:
            pos = q.popleft()
            
            if pos == end:
                continue
                
            x, y = pos
            
            for dx, dy in d:
                nx = x + dx
                ny = y + dy
                if nx < 0 or ny < 0:
                    continue
                
                if memo[(nx, ny)] == 0:
                    q.append((nx, ny))
                memo[(nx, ny)] += memo[pos]
            
        return memo[end]
        
