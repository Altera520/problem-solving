from collections import defaultdict, deque


def bfs(prev, st, graph):
    visit = defaultdict(bool)
    visit[prev] = visit[st] = True
    q = deque([st])
    count = 0
    
    while q:
        current = q.pop()
        count += 1
        for next_node in graph[current]:
            if visit[next_node]:
                continue
            q.append(next_node)
            visit[next_node] = True
    return count
    

def solution(n, wires):
    answer = n + 1
    graph = defaultdict(list)
    count = defaultdict(list)
    
    for src, dst in wires:
        graph[src].append(dst)
        graph[dst].append(src)
        
    for k in graph.keys():
        sum = 0
        for next_node in graph[k]:
            res = bfs(k, next_node, graph)
            count[k].append(res)
            sum += res
        count[k].append(sum)
            
    for k in count.keys():
        sum = count[k][-1]
        for p in count[k][:-1]:
            answer = min(abs(sum - p + 1 - p), answer)
            
    return answer
