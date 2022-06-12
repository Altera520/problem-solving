class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ans = 0
        
        while target != 1:
            if target % 2 == 0 and maxDoubles:
                target //= 2
                maxDoubles -= 1
                ans += 1
            elif maxDoubles:
                target -= 1
                ans += 1
            else:
                ans += (target - 1)
                target = 1
        return ans
