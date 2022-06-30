from collections import defaultdict

class Solution:
    def frequencySort(self, s: str) -> str:
        d = defaultdict(int)
        for ch in s:
            d[ch] += 1
            
        return ''.join([k * -v for v, k in sorted([(-v, k) for k, v in d.items()])])


