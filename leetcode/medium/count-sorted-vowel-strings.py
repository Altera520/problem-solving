class Solution:
    def __init__(self):
        self.count = 0
        
    def countVowelStrings(self, n: int) -> int:
        vowel = ['a', 'e', 'i', 'o', 'u']
        
        def iter(src, step):
            for dst in vowel:
                if src > dst:
                    continue
                if step < n:
                    iter(dst, step + 1)
                else:
                    self.count += 1
                    
        iter('', 1)
        return self.count
