from collections import deque

def solution(maps):
    answer = 0
    
    q = deque([(0, 0, 1)])
    d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    m = len(maps)
    n = len(maps[0])
    visit = [[False] * n for _ in range(m)]
    
    while q:
        y, x, step = q.popleft()
        if (y, x) == (m - 1, n - 1):
            return step
        
        for dy, dx in d:
            ny = y + dy
            nx = x + dx
            if not (0 <= ny < m and 0 <= nx < n):
                continue
            if visit[ny][nx] or maps[ny][nx] == 0:
                continue
            visit[ny][nx] = True
            q.append((ny, nx, step + 1))
    
    return -1
