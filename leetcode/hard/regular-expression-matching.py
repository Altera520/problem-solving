import re

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        pattern = re.compile(p)
        match = pattern.match(s)
        
        return True if match and match.group() == s else False
        
