class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort()

        def is_overlap(v1, v2):
            st, ed = v1
            return st <= v2[0] <= ed

        ans = []
        i = 0
        cur = intervals[i]
        while i != len(intervals) - 1:
            i += 1
            _next = intervals[i]
            if is_overlap(cur, _next):
                cur = (cur[0], max(cur[1], _next[1]))
            else:
                ans.append(cur)
                cur = _next
        ans.append(cur)

        return ans
