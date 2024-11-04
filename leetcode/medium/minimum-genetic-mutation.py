from collections import defaultdict, deque

class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bank.append(startGene)

        def diff(l, r):
            count = 0
            for i, ch in enumerate(l):
                if ch != r[i]:
                    count += 1
            return count

        graph = defaultdict(list)
        
        for i in range(len(bank)):
            for j in range(len(bank)):
                if i == j:
                    continue
                if diff(bank[i], bank[j]) == 1:
                    graph[bank[i]].append(bank[j])
        visit = {}

        q = deque([(startGene, 0)])
        visit[startGene] = True

        while q:
            cur, cnt = q.popleft()
            if cur == endGene:
                return cnt
            for _next in graph[cur]:
                if _next in visit:
                    continue
                q.append((_next, cnt + 1))
                visit[_next] = True
        return -1
