class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        d = defaultdict(list)
        
        for i in range(n):
            for j in range(n):
                if i == j or isConnected[i][j] == 0:
                    continue
                d[i].append(j)
                d[j].append(i)
        
        visit = defaultdict(bool)
        def bfs(st):
            q = deque([st])
            visit[st] = True
            while q:
                src = q.popleft()
                for dst in d[src]:
                    if visit[dst]:
                        continue
                    q.append(dst)
                    visit[dst] = True
        
        province = 0
        for i in range(n):
            if not visit[i]:
                bfs(i)
                province += 1
        return province
