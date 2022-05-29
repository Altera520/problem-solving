class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        d = {}
        w = {}
        
        if len(words) != len(pattern):
            return False
        
        for idx, k in enumerate(pattern):
            if k not in d:
                d[k] = words[idx]
                w[words[idx]] = 0
                continue
            
            if d[k] != words[idx]:
                return False
        
        
        if len(w.keys()) != len(d.keys()):
            return False
        
        return True
            
