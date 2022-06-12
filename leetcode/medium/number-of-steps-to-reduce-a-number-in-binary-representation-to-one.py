class Solution:
    def numSteps(self, s: str) -> int:
        base = 1
        num = 0
        for i in range(len(s) - 1, -1, -1):
            num += (int(s[i]) * base)
            base *= 2
        
        cnt = 0
        while num != 1:
            if num % 2 == 0:
                num //= 2
            else:
                num += 1
            cnt += 1
        return cnt
