def solution(s):
    stack = []
    SUCCESS, FAIL = (1, 0)
    
    push = lambda item: stack.append(item)
    pop = lambda : stack.pop()
    peek = lambda : stack[-1] if len(stack) != 0 else None
    
    for ch in s:
        item = peek()
        if item is not None and item == ch:
            pop()
        else:
            push(ch)

    return SUCCESS if len(stack) == 0 else FAIL
