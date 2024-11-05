from collections import deque

class Solution:
    def simplifyPath(self, path: str) -> str:
        q = deque()
        for p in path.split('/'):
            if not p or p == '.':
                continue
            if p == '..':
                if q:
                    q.pop()
            else:
                q.append(p)
        return '/' + '/'.join(list(q))
