class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        prev = 0
        spaces.append(len(s))
        for space in spaces:
            ans.append(s[prev: space])
            prev = space
        return ' '.join(ans).rstrip()
