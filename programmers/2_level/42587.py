from collections import deque

def solution(priorities, location):
    dq = deque([(v, k) for k, v in enumerate(priorities)])
    desc = sorted(priorities, reverse=True)
    answer = 0
    
    while True:
        v, k = dq.popleft()
        
        if desc[answer] != v:
            dq.append((v, k))
            continue
            
        answer += 1
        
        if location == k:
            break
    
    return answer
