def solution(s):
    is_empty = lambda stack: len(stack) == 0
    peek = lambda stack: stack[-1]
    stack = []
    
    for ch in s:
        if not is_empty(stack) and (peek(stack), ch) == ('(', ')'):
            stack.pop()
            continue
        stack.append(ch)
        
    return is_empty(stack)
