from itertools import permutations

def solution(k, dungeons):
    cases = permutations(dungeons)
    ans = 0
    
    for case in cases:
        stat = k
        count = 0
        for dungeon in case:
            require, consume = (dungeon[0], dungeon[1])
            if stat < require:
                break
            count += 1
            stat -= consume
        ans = max(count, ans)
    
    return ans
