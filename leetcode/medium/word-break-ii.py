class Solution:
    size_map = {}
    
    def permutation(self, s, wordDict, words, size, limit, ans):
        if size == limit and ''.join(words) == s:
            ans.append(' '.join(words)) 
            return ans
            
        for word in wordDict:
            tmp = Solution.size_map[word] + size
            if tmp > limit:
                continue
            
            words.append(word)
            self.permutation(s, wordDict, words, tmp, limit, ans)
            words.pop(-1)
        return ans
            
    
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        for word in wordDict:
            Solution.size_map[word] = len(word)
            
        return self.permutation(s, wordDict, [], 0, len(s), [])
