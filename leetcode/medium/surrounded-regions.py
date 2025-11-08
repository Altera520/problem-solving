from collections import deque

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        # y, x
        d = [
            (1 ,0),
            (-1 ,0),
            (0 ,-1),
            (0 ,1),
        ]
        visit = {}

        m = len(board)
        n = len(board[0])

        def bfs(seed):
            flag = True
            q = deque([seed])
            tmp = []

            while q:
                curr = q.popleft()
                tmp.append(curr)
                visit[curr] = True
                y, x = curr

                for dy, dx in d:
                    ny = y + dy
                    nx = x + dx
                    _next = (ny, nx)

                    if not (0 <= ny < m and 0 <= nx < n):
                        flag = False
                    elif _next not in visit and board[ny][nx] == 'O':
                        visit[_next] = True
                        q.append(_next)
            if flag:
                for y, x in tmp:
                    board[y][x] = 'X'


        for y in range(0, m):
            for x in range(0, n):
                if board[y][x] == 'O' and (y, x) not in visit:
                    bfs((y, x))

