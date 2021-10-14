from collections import deque
import copy

# row, col
D = [(1, 0), (0, 1), (-1, 0), (0, -1)]
EMPTY = 0
FILL = 1


def bfs(entry, source_graph, blank):
    def is_out_of_bound(point, graph):
        row, col = point
        return not (0 <= row < len(graph) and 0 <= col < len(graph[0]))

    def is_movable(point, graph):
        row, col = point
        return graph[row][col] == EMPTY
    
    def fill(point, graph):
        row, col = point
        graph[row][col] = FILL
    
    def is_all_fill(cnt, blank):
        return cnt == blank
    
    graph = copy.deepcopy(source_graph)
    step = 0
    cnt = 0
    q = deque(entry)

    while q:
        
        cur_row, cur_col, cur_step = q.popleft()
        step = max(step, cur_step)

        for d_row, d_col in D:
            next_point = (cur_row + d_row, cur_col + d_col)

            if is_out_of_bound(next_point, graph):
                continue
            if not is_movable(next_point, graph):
                continue

            q.append(next_point + (cur_step + 1,))
            fill(next_point, graph)
            cnt += 1
    
    return step if is_all_fill(cnt, blank) else -1


def solution():   
    m, n = map(int, input().split())
    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().split())))

    entry = []
    blank = 0
    for y in range(n):
        for x in range(m):
            if graph[y][x] == FILL:
                entry.append((y, x) + (0,))
            elif graph[y][x] == EMPTY:
                blank += 1
    
    print(bfs(entry, graph, blank))

if __name__ == '__main__':
    solution()
