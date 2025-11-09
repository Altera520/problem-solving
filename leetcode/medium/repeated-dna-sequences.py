from collections import defaultdict

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        sz = len(s)
        d = defaultdict(int)
        ans = []

        if sz < 10:
            return ans

        st, ed = 0, 10

        for i in range(sz - 9):
            d[s[st:ed]] += 1
            st += 1
            ed += 1
        
        for k, v in d.items():
            if v > 1:
                ans.append(k)
        
        return ans
        
