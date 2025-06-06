from collections import defaultdict, deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        courses = defaultdict(list)
        ref = defaultdict(int)
        ans = []

        for i in range(0, numCourses):
            courses[i] = []
            ref[i] = 0

        for pre in prerequisites:
            dst, src = tuple(pre)
            courses[src].append(dst)
            ref[dst] += 1

        q = deque([k for k, v in ref.items() if v == 0])

        while q:
            curr = q.popleft()
            if ref[curr] != 0:
                ref[curr] -= 1
            if ref[curr] == 0:
                ans.append(curr)
                for next in courses[curr]:
                    q.append(next)

        if not prerequisites:
            return [i for i in range(0, numCourses)]
        elif len(ans) == numCourses:
            return ans
        else:
            return []
