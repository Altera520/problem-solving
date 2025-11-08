from collections import defaultdict, deque

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        ans = []
        graph = defaultdict(list)

        for i, eq in enumerate(equations):
            _from, _to = tuple(eq)
            graph[_from].append((_to, values[i]))
            graph[_to].append((_from, 1 / values[i]))

        def calc(src, dst):
            if src not in graph or dst not in graph:
                return -1.0
            if src == dst:
                return 1.0

            q = deque([(src, 1.0)])
            visit = {src: True}

            while q:
                curr, v = q.popleft()
                for _next, nv in graph[curr]:
                    if _next in visit:
                        continue
                    if _next == dst:
                        return v * nv
                    q.append((_next, v * nv))
                    visit[_next] = True
            return -1.0
        
        for query in queries:
            src, dst = tuple(query)
            ans.append(calc(src, dst))

        return ans
