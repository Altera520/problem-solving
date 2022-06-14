class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        d = {}
        pattern = pattern.upper()
        for idx, v in enumerate(pattern):
            d[v] = idx
        ans = []
        for word in words:
            temp = pattern[:]
            d2 = {}
            for k, v in d.items():
                temp = temp.replace(k, word[v])
                d2[word[v]] = 0
            if temp == word and len(d.keys()) == len(d2.keys()):
                ans.append(word)
        return ans
        
