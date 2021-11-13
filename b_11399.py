def minimum_result(n, p):
    ans = 0
    tmp = [0 for _ in range(n + 1)]
    p.sort()
    for i in range(1, n + 1):
        tmp[i] = tmp[i-1] + p[i]
    for _ in tmp:
        ans += _
    return ans


def solution():
    n = int(input())
    p = [0] + list(map(int, input().split()))
    print(minimum_result(n, p))

if __name__ == '__main__':
    solution()