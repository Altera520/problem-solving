from collections import defaultdict, deque

class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        visit = {}
        d = defaultdict(list)
        q = deque()
        ans = 0
        acc = 0

        for src, dst in edges:
            d[src].append(dst)
            d[dst].append(src)
        
        for node in range(0, n):
            if node in visit:
                continue

            cnt = 0
            q.append(node)
            visit[node] = True
            
            while q:
                curr = q.popleft()
                cnt += 1

                for next in d[curr]:
                    if next in visit:
                        continue
                    q.append(next)
                    visit[next] = True
            ans += acc * cnt
            acc += cnt

        return ans
