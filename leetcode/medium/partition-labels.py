class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        tmp = []
        d = {}
        pat = 0

        for idx, ch in enumerate(s):
            d[ch] = idx

        for idx, ch in enumerate(s):
            pat = max(pat, d[ch])
            if idx == pat:
                tmp.append(pat)

        ans = []
        for idx in range(len(tmp)):
            if idx == 0:
                ans.append(tmp[idx] + 1)
            else:
                ans.append(tmp[idx] - tmp[idx - 1])
        
        return ans