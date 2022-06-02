class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        partition = len(s1)
        s1 = sorted(s1)
        for i in range(0, len(s2) - partition + 1):
            substr = sorted(s2[i:i+partition])
            if s1 == substr:
                return True
        return False
                
