from collections import defaultdict

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        w_desc = None
        st, ed = 0, len(p)

        def describe(ss):
            res = defaultdict(int)
            for ch in ss:
                res[ch] += 1
            return res

        def diff(base, other):
            for keys in [base.keys(), other.keys()]:
                for k in keys:
                    if base[k] != other[k]:
                        return False
            return True

        p_desc = describe(p)

        while ed <= len(s):
            if w_desc is None:
                w_desc = describe(s[st:ed])
            else:
                w_desc[s[ed - 1]] += 1

            if diff(p_desc, w_desc):
                ans.append(st)

            w_desc[s[st]] -= 1
            st += 1
            ed += 1

        return ans
