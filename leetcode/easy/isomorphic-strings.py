class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d = {}
        seq1 = 0
        seq2 = 0
        
        for i in range(len(s)):
            k1 = (ord(s[i]), '*')
            k2 = ('*', ord(t[i]))
            
            if k1 not in d:
                d[k1] = seq1
                seq1 += 1
            if k2 not in d:
                d[k2] = seq2
                seq2 += 1
                
            if d[k1] != d[k2]:
                return False
        return True
