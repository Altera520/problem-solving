from collections import deque

class Solution:

    def is_palindrome(self, s: str) -> bool:
        mid = len(s) // 2
        if len(s) == 1:
            return True
        elif len(s) % 2 == 0:
            return s[0:mid] == s[mid:][::-1]
        else:
            return s[0:mid] == s[mid + 1:][::-1]


    def partition(self, s: str) -> List[List[str]]:
        ans = []
        q = deque([(s, [], 0)])
        sz = len(s)

        while q:
            v, bucket, cnt = q.popleft()
            if cnt == sz:
                ans.append(bucket)
                continue
            for seed in range(1, len(v) + 1):
                sub_v = v[0:seed]
                if self.is_palindrome(sub_v):
                    q.append((v[seed:], bucket.copy() + [sub_v], cnt + len(sub_v)))
        return ans
