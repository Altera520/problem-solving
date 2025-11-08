from collections import deque
import math

class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        q = [math.inf]
        ans = []
        st, ed = 0, 1

        for i, ch in enumerate(s):
            if ch == c:
                q.append(i)
        q.append(math.inf)
        
        for i, ch in enumerate(s):
            ans.append(min(abs(q[st] - i), abs(q[ed] - i)))
            if ch == c:
                st += 1
                ed += 1
        
        return ans

