class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        sz = len(s)
        s = s + (fill * ((k - sz % k) % k))
        return [s[i:i+k] for i in range(0, sz, k)]

