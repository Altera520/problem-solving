from collections import deque


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        
        q = deque([(0, [0])])
        ans = []
        end = len(graph) - 1

        while q:
            cur, path = q.popleft()

            for next in graph[cur]:
                q.append((next, path + [next]))

            if path[-1] == end:
                ans.append(path)

        return ans
