# nCr, processing
def combination(n, r, st = 1, tmp = [], answer = []):
    if r == 0:
        answer.append(tmp[:])
        return 
        
    for item in range(st, n):
        tmp.append(item)
        combination(n, r - 1, item + 1, tmp, answer)
        tmp.pop()
        
    return answer


# output
def solution(n, m):
    for set in combination(n + 1, m):
        print(*set)


# input
if __name__ == '__main__':
    solution(*map(int, input().split()))
    
