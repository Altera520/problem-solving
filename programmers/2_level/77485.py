def solution(rows, columns, queries):
    cnt = 0
    graph = [[]]
    for _ in range(rows + 1):
        graph.append([])
        graph[-1].append(0)
        for _ in range(columns):
            cnt += 1
            graph[-1].append(cnt)
    
    # right, down, left, up
    move = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    def spin(query):
        d = 0
        st = (query[0], query[1])
        y, x = st
        bef = graph[y][x]
        v = bef
        
        while True:
            if (y, x) in [(query[0], query[3]), (query[2], query[3]), (query[2], query[1])]:
                d += 1
            ny, nx = (y + move[d][0], x + move[d][1])
            
            tmp = graph[ny][nx]

            v = min(v, tmp)
            graph[ny][nx] = bef
            bef = tmp
            
            if (ny, nx) == st:
                break
            y, x = (ny, nx)
        return v
            
    return [spin(query) for query in queries]
