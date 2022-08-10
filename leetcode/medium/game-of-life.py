from itertools import permutations

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        LIVE, DEAD, LIVE_TO_DEAD, DEAD_TO_LIVE = 1, 0, 3, 2
        m = len(board)
        n = len(board[0])
        d = list(set(permutations([1, 1, 0, -1, -1], 2)))
        
        def live_or_dead(y, x):
            count = 0
            for dy, dx in d:
                ny = y + dy
                nx = x + dx
                if not (0 <= ny < m and 0 <= nx < n):
                    continue
                if board[ny][nx] % 2 == LIVE:
                    count += 1

            # rule
            state = board[y][x] % 2
            if state == LIVE and count < 2:
                return LIVE_TO_DEAD
            if state == LIVE and count <= 3:
                return LIVE
            if state == LIVE and count > 3:
                return LIVE_TO_DEAD
            if state == DEAD and count == 3:
                return DEAD_TO_LIVE
            return state
        
        for y in range(m):
            for x in range(n):
                board[y][x] = live_or_dead(y, x)
                
        for y in range(m):
            for x in range(n):
                if board[y][x] >= 2:
                    board[y][x] = 3 % board[y][x]
            
