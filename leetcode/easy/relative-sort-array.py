from itertools import chain

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        d = {}
        for item in arr2:
            d[item] = 0
        
        postfix = []
        for item in arr1:
            if item in d:
                d[item] += 1
            else:
                postfix.append(item)
        
        return list(chain.from_iterable([[item] * d[item] for item in arr2])) + sorted(postfix)
