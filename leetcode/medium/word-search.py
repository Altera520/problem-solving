from collections import deque

class Solution:        
    def exist(self, board: List[List[str]], word: str) -> bool:
        d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        is_in = lambda nx, ny: 0 <= nx < len(board[0]) and 0 <= ny < len(board)
        sz = len(word)
        
        def dfs(st, tmp, graph):
            if len(tmp) == sz:
                return ''.join(tmp) == word
                    
            x, y = st
            ch = graph[y][x]
            graph[y][x] = None
            for dx, dy in d:
                nx = x + dx
                ny = y + dy

                if not is_in(nx, ny):
                    continue
                if not graph[ny][nx]:
                    continue
                if word[len(tmp)] == graph[ny][nx] and dfs((nx, ny), tmp + [graph[ny][nx]], graph):
                    return True
            graph[y][x] = ch
            return False
        
        
        for y, row in enumerate(board):
            for x, _ in enumerate(row):
                if board[y][x] == word[0] and dfs((x, y), [word[0]], board):
                    return True
        return False
