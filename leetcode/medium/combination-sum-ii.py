from collections import defaultdict

class Solution:
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        d = defaultdict(int)
        for c in [c for c in candidates if c <= target]:
            d[c] += 1
            
        candidates = sorted(d.keys())
        size = len(candidates)
        
        
        def append(tmp, item, idx, val):
            tmp.append(item)
            val += item
            next = idx if d[item] != 1 else idx + 1
            if next == idx:
                d[item] -= 1
            return val ,next
        
        def pop(tmp, item, val, flag):
            tmp.pop()
            val -= item
            if flag:
                d[item] += 1
            return val

        
        def comb(answer, tmp, val, index):
            if val == target:
                answer.append(tmp[:])
                return answer
            
            for i in range(index, size):
                item = candidates[i]
                if item + val > target:
                    continue
                val, next = append(tmp, item, i, val)
                comb(answer, tmp, val, next)
                val = pop(tmp, item, val, next == i)
            return answer
        
        return comb([], [], 0, 0)
            
        
