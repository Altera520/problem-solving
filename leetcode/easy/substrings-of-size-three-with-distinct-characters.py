class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        return len([substring for substring in [s[i:i + 3] for i in range(len(s) - 2)] if len(set(substring)) == 3])
            
