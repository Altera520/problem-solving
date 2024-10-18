from collections import defaultdict


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:

        class DisjointSet:
            def __init__(self, size):
                self.bucket = list(range(0, size + 1))

            def find(self, x):
                if self.bucket[x] != x:
                    self.bucket[x] = self.bucket[self.bucket[x]]
                return self.bucket[x]

            def union(self, a, b):
                a = self.find(a)
                b = self.find(b)
                parent, child = (a, b) if a < b else (b, a)
                self.bucket[child] = parent
                return parent, child

        emails = {}
        candidates = defaultdict(list)

        for i, account in enumerate(accounts):
            id = hash(str(i))
            name = account[0]
            emails[id] = set(account[1:])
            candidates[name].append(id)
        
        ans = []
        for name, ids in candidates.items():
            ds = DisjointSet(len(ids))
            ids = [0] + ids

            for i in range(1, len(ids)):
                for j in range(1, len(ids)):
                    if i == j:
                        continue
                    if ds.find(i) == ds.find(j):
                        continue
                    if emails[ids[i]] & emails[ids[j]]:
                        parent, child = ds.union(i, j)
                        emails[ids[parent]].update(emails[ids[child]])
                        emails[ids[i]] = emails[ids[parent]]

            for i in set(ds.bucket[1:]):
                ans.append([name] + sorted(emails[ids[i]]))
        
        return ans