from collections import defaultdict

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        tmp = defaultdict(int)
        sz = len(strs)
        
        for word in strs:
            for pos, char in enumerate(word):
                tmp[(pos, char)] += 1
        
        count = 0
        for v in tmp.values():
            if v != sz:
                break
            count += 1
        
        return strs[0][0:count] if count != -1 else ''
        
