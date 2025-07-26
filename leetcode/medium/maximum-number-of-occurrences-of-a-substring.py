from collections import defaultdict

class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        d = defaultdict(int)
        sz = len(s)

        for window in range(minSize, maxSize + 1):

            tmp = defaultdict(int)
            for i in range(window):
                tmp[s[i]] += 1

            st, ed = 0, window
            for _ in range(sz - window + 1):

                if len(tmp) <= maxLetters:
                    d[s[st:ed]] += 1
                
                # move
                if sz == ed:
                    break

                tmp[s[st]] -= 1
                if tmp[s[st]] == 0:
                    del tmp[s[st]]
                tmp[s[ed]] += 1
                st += 1
                ed += 1

        return max(d.values() if d else [0])