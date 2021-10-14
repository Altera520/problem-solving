from collections import deque
from collections import defaultdict

def bfs(node, graph, visit):
    q = deque([node])
    visit[node] = True
    cnt = 0

    while q:
        for next in graph[q.popleft()]:
            if visit[next]:
                continue
            q.append(next)
            visit[next] = True
            cnt += 1

    return cnt


def solution():
    v = int(input())
    e = int(input())

    graph = defaultdict(list)
    visit = [False for _ in range(v + 1)]
    for _ in range(e):
        f, t = map(int, input().split())
        graph[f].append(t)
        graph[t].append(f)

    print(bfs(1, graph, visit))


if __name__ == '__main__':
    solution()
