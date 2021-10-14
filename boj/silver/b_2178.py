from collections import deque

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
        return not (0 <= row < len(graph) and 0 <= col < len(graph[0]))

    def is_empty(point, graph):
        row, col = point
        return graph[row][col] == EMPTY

    def is_end(point, graph):
        row, col = point
        return row == len(graph) - 1 and col == len(graph[0]) - 1
    
    q = deque([point + (1,)])
    do_visit(point, visit)

    while q:
        cur_row, cur_col, count = q.popleft()
        for d_row, d_col in D:
            next_point = (cur_row + d_row, cur_col + d_col)
            
            if (is_out_of_bound(next_point, graph)):
                continue
            if (is_visit(next_point, visit)):
                continue
            if (is_empty(next_point, graph)):
                continue
            if (is_end(next_point, graph)):
                return count + 1

            q.append(next_point + (count + 1,))
            do_visit(next_point, visit)
    return 0


def solution():   
    n, m = map(int, input().split())
    graph = []
    visit = [[False for _ in range(m)] for _ in range(n)]
    for _ in range(n):
        graph.append(input())
    
    print(bfs((0,0), graph, visit))


if __name__ == '__main__':
    solution()
