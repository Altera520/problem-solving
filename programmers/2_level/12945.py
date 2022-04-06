def solution(n):
    d = [0, 1]
    
    for i in range(2, n + 1):  
        d.append(d[i - 1] + d[i - 2])
        
    return d[i] % 1234567

# =========================================
# maximum recursion depth exceeded가 나기때문에 재귀한도를 높여준다
import sys
sys.setrecursionlimit(10**6)

d = {0: 0, 1: 1}

def f(n):
    if n in d:
        return d[n]
    d[n] = (f(n - 1) + f(n - 2)) % 1234567
    return d[n]


def solution(n):
    return f(n)
