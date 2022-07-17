from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        EMPTY, O, RO = (0, 1, 2)
        d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        m = len(grid)
        n = len(grid[0])
        stage = []
        
        def rott(pt):
            temp = []
            y, x = pt
            for dy, dx in d:
                ny = y + dy
                nx = x + dx
                if not (0 <= ny < m and 0 <= nx < n) :
                    continue
                if grid[ny][nx] == O:
                    grid[ny][nx] = RO
                    temp.append((ny, nx))
            return temp
                    
        
        t = 0
        num = 0
        for y in range(m):
            for x in range(n):
                if grid[y][x] == RO:
                    stage.append((y, x))
                if grid[y][x] != EMPTY:
                    num += 1 
                    
        while True:
            flag = False
            temp = []
            num -= len(stage)
            for pt in  stage:
                temp += rott(pt)
            stage = temp
            if len(stage) == 0:
                break
            t += 1
                    
        return t if num == 0 else -1
        
