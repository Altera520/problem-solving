from collections import defaultdict

class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        ans = 0
        record = defaultdict(int)
        pairs = sorted(list(zip(values, labels)), reverse=True)

        for value, label in pairs:
            if record[label] < useLimit:
                ans += value
                record[label] += 1
                numWanted -= 1
            if numWanted == 0:
                break
        return ans