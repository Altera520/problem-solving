from collections import deque
from queue import PriorityQueue

# row, col
D = [(1, 0), (0, 1), (-1, 0), (0, -1)]
EMPTY = '0'


def bfs(point, graph, visit):
    def is_visit(point, visit):
        row, col = point
        return visit[row][col]

    def do_visit(point, visit):
        row, col = point
        visit[row][col] = True

    def is_out_of_bound(point, graph):
        row, col = point
        bound = lambda x: 0 <= x < len(graph)
        return not (bound(row) and bound(col))

    def is_empty(point, graph):
        row, col = point
        return graph[row][col] == EMPTY

    cnt = 0
    if (is_visit(point, visit) or is_empty(point, graph)):
        return cnt
    
    q = deque([point])
    do_visit(point, visit)

    while q:
        cur_row, cur_col = q.popleft()
        cnt += 1
        for d_row, d_col in D:
            next_point = (cur_row + d_row, cur_col + d_col)

            if (is_out_of_bound(next_point, graph)):
                continue
            if (is_visit(next_point, visit)):
                continue
            if (is_empty(next_point, graph)):
                continue

            q.append(next_point)
            do_visit(next_point, visit)

    return cnt


def solution():
    graph = []
    n = int(input())
    visit = [[False for _ in range(n)] for _ in range(n)]
    pq = PriorityQueue()

    for _ in range(n):
        graph.append(input())

    for row in range(n):
        for col in range(n):
            res = bfs((row, col), graph, visit)
            if res != 0:
                pq.put(res)

    print(pq.qsize())
    while not pq.empty():
        print(pq.get())


if __name__ == '__main__':
    solution()
