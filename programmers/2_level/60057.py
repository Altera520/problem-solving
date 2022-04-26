def solution(s):
    sz = len(s)
    answer = sz
    
    for i in range(1, sz // 2 + 1):
        padding = (i - (sz % i)) % i
        tmp = s + (' ' * padding)
        count = 0
        stack = []
        
        for j in range(0, sz + padding, i):
            piece = tmp[j:j + i]
            if stack and stack[-1][0] == piece:
                stack[-1][1] += 1
                continue
            stack.append([piece, 1])
        
        for _, num in stack:
            count += i
            if num != 1:
                count += len(str(num))
        answer = min(answer, count - padding)
    
    return answer
