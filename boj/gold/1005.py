from collections import defaultdict, deque
import sys

def _input():
    return map(int, sys.stdin.readline().split())

def solution():
    vertax, edge = _input()
    node = [0]
    node += list(_input())
    
    graph = defaultdict(list)
    indegree = defaultdict(int)
    accumulate = node[:]        # shallow copy
    
    for _ in range(edge):
        src, dest = _input()
        graph[src].append(dest)
        indegree[dest] += 1

    end = int(input())

    q = deque([k for k in range(1, vertax + 1) if indegree[k] == 0])
    
    while len(q) != 0:
        src = q.popleft()
    
        for dest in graph[src]:
            indegree[dest] -= 1
            accumulate[dest] = max(accumulate[dest], node[dest] + accumulate[src])

            if indegree[dest] == 0:
                q.append(dest)
            
    return accumulate[end]

if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        print(solution())
