class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0] )
        # down, up
        direction = [(1, -1), (-1, 1)]
        lvl_change = [(1, 0), (0, 1)]
        
        y, x = (0, 0)
        d = 1
        ans = []
        valid = lambda ny, mx: 0 <= ny < m and 0 <= nx < n        
        
        while True:
            ans.append(mat[y][x])
            dy, dx = direction[d]
            ny = y + dy
            nx = x + dx

            if not valid(ny, nx):
                dy, dx = lvl_change[d]
                ny = y + dy
                nx = x + dx
                if not valid(ny, nx):
                    dy, dx = lvl_change[abs(d - 1)]
                    ny = y + dy
                    nx = x + dx
                    if not valid(ny, nx):
                        break
                d = abs(d - 1)
            y = ny
            x = nx
        return ans
