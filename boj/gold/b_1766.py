from collections import defaultdict
from queue import PriorityQueue

def problem_sort(n, m):
    graph = defaultdict(list)
    indegree = defaultdict(int)
    pq = PriorityQueue()
    ans = []

    for _ in range(m):
        up, down = map(int, input().split())
        graph[up].append(down)
        indegree[down] += 1

    for i in range(1, n + 1):
        if indegree[i] == 0:
            pq.put(i)
    
    while not pq.empty():
        cur = pq.get()
        ans.append(cur)

        for next in graph[cur]:
            indegree[next] -= 1
            if indegree[next] == 0:
                pq.put(next)
    return ans


def solution():
    for i in problem_sort(*map(int, input().split())):
        print(i, end=' ')


if __name__ == '__main__':
    solution()
