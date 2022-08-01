from collections import deque, defaultdict

class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        graph = defaultdict(list)
        order = defaultdict(list)
        
        for src, dst in edges:
            graph[src].append(dst)
            graph[dst].append(src)
        
        q = deque([(0, 0)])
        visit = [False for _ in range(len(hasApple))]
        visit[0] = True
        while q:
            cur, step = q.popleft()
            order[step].append(cur)
            for child in graph[cur]:
                if visit[child]:
                    continue
                q.append((child, step + 1))
                visit[child] = True
        
        ans = 0
        for lvl in range(max(order), 0, -1):
            for node in order[lvl]:
                if not hasApple[node]:
                    continue
                for adj in graph[node]:
                    hasApple[adj] = True
                ans += 2 
        return ans
