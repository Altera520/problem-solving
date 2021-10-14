from collections import deque

# row, col
D = [(1, 0), (0, 1), (-1, 0), (0, -1)]
EMPTY = 0


def bfs(point, graph, visit):
    def is_visit(point, visit):
        row, col = point
        return visit[row][col]

    def do_visit(point, visit):
        row, col = point
        visit[row][col] = True

    def is_out_of_bound(point, graph):
        row, col = point
        return not (0 <= row < len(graph) and 0 <= col < len(graph[0]))

    def is_empty(point, graph):
        row, col = point
        return graph[row][col] == EMPTY

    if (is_visit(point, visit) or is_empty(point, graph)):
        return 0
    
    q = deque([point])
    do_visit(point, visit)

    while q:
        cur_row, cur_col = q.popleft()
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
    return 1


def solution():   
    m, n, k = map(int, input().split())
    graph = [[0 for _ in range(m)] for _ in range(n)]
    visit = [[False for _ in range(m)] for _ in range(n)]
    ans = 0

    for _ in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1
    
    for y in range(n):
        for x in range(m):
            ans += bfs((y, x), graph, visit)
    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solution()
