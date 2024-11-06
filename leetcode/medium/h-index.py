from collections import defaultdict

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        l = len(citations)
        h = 0
        for i in range(l):
            if i - 1 >= 0 and citations[i] == citations[i - 1]:
                continue
            h = max(min(citations[i], l - i), h)
        return h
