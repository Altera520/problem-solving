from collections import defaultdict

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        
        ans = []
        i = 0
        sz = len(intervals)
        while True:
            if i + 1 == sz:
                ans.append(intervals[i])
                break
            cur_st, cur_ed = tuple(intervals[i])
            next_st, next_ed = tuple(intervals[i + 1])

            if cur_st <= next_st <= cur_ed:
                intervals[i + 1] = [cur_st, max(cur_ed, next_ed)]
            else:
                ans.append(intervals[i])
            i += 1
        return ans 
