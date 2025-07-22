class Solution:
    def longestWord(self, words: List[str]) -> str:
        d = {}
        longest = 1
        seq = sorted([(len(word), word) for word in words], reverse=True)
        for word in words:
            d[word] = None

        for _, word in seq:
            if d[word] is not None: # visited
                continue

            candidate = word
            tmp = []
            pad = 0
            flag = False
            while True:
                if candidate in d:
                    if d[candidate] is not None: 
                        if d[candidate] == -1:
                            flag = True
                        pad = d[candidate]
                        break
                    else:
                        tmp.append(candidate)
                else:
                    flag = True
                    break
                if len(candidate) == 1:
                    break
                candidate = candidate[:-1]

            sz = len(tmp) + pad
            for i, word in enumerate(tmp):
                if flag:
                    d[word] = -1
                else:
                    d[word] = sz - i
                longest = max(d[word], longest)

        candidates = [k for k, v in d.items() if v == longest]
        if candidates:
            return min(candidates)
        else:
            return ""

