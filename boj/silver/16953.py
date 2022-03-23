from collections import deque


def solution(a, b):
    q = deque([(a, 0)])
    answer = -2
    while q:
        number, count = q.popleft()
        if number > b:
            continue
        if number == b:
            answer = count
            break
        count += 1
        q.append((number * 2, count))
        q.append((number * 10 + 1, count))
    return answer + 1
    

if __name__ == '__main__':
    print(solution(*map(int, input().split())))
