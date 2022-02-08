numbs = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']

class Solution:    
    
    def comb(self, digits, n, item, ans):
        if len(digits) == n:
            ans.append(item)
            return
            
        for ch in numbs[int(digits[n]) - 2]:
            self.comb(digits, n + 1, ''.join([item, ch]), ans)
        return ans
    
    def letterCombinations(self, digits: str) -> List[str]:
        return self.comb(digits, 0, '', [])
