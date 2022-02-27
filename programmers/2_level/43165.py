from collections import deque

def solution(numbers, target):
    numbers = [0] + numbers
    add = lambda x, y: x + y
    sub = lambda x, y: x - y
    op_list = [add, sub]
    q = deque([(0, 0, 0), (0, 0, 1)])
    
    ans = 0
    
    while len(q) != 0:
        value, idx, cur_op = q.popleft()
        
        if idx == len(numbers) - 1:
            if value == target:
                ans += 1
            continue
        
        for op in range(2):
            tmp = (
                op_list[cur_op](value, numbers[idx + 1]),
                idx + 1,
                op)
            q.append(tmp)
    
    return ans // 2
