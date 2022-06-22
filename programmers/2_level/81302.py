from collections import deque

def solution(places):
    PERSON = 'P'
    PARTITION = 'X'
    d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    valid = lambda y, x: 0 <= y < 5 and 0 <= x < 5
    manhatten = lambda pt1, pt2: abs(pt1[0] - pt2[0]) + abs(pt1[1] - pt2[1]) <= 2
    
    def bfs(st, place):
        q = deque([st])
        visit = [[False] * 5 for _ in range(5)]
        visit[st[0]][st[1]] = True
        while q:
            y, x = q.popleft()
            for dy, dx in d:
                ny = y + dy
                nx = x + dx
                if not valid(ny, nx):
                    continue
                if place[ny][nx] == PARTITION or visit[ny][nx]:
                    continue
                m = manhatten(st, (ny, nx))
                if place[ny][nx] == PERSON and m:
                    return 0
                if not m:
                    continue
                q.append((ny, nx))
                visit[ny][nx] = True
        return 1
    
    def keep_distance(place):
        persons = [(y, x) for y in range(5) for x in range(5) if place[y][x] == PERSON]
        for pt in persons:
            if bfs(pt, place) == 0:
                return 0
        return 1
    
    return [keep_distance(place) for place in places]
