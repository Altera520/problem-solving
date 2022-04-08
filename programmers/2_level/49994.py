def solution(dirs):
    pos = (0, 0)
    d = {'U': (0, 1), 'D': (0, -1), 'R': (1, 0), 'L': (-1, 0)}
    visit = {}
    possible = lambda v: len(list(filter(lambda item: -5 <= item <= 5, v))) == 2
    mv = lambda v1, v2: (v1[0] + v2[0], v1[1] + v2[1])
    
    for dir in dirs:
        src = pos
        dst = mv(d[dir], pos)
        
        if possible(dst):
            visit[(src, dst)] = visit[(dst, src)] = True
            pos = dst
            
    return len(visit.keys()) // 2
