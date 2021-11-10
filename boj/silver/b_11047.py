def minimum_result(n, k, data):
    ans = 0
    data.sort()
    for coin in data[::-1]:
        div = k // coin
        if div == 0:
            continue
        ans += div
        k %= coin
        if k == 0:
            break
    return ans


def solution():
    n, k = map(int, input().split())
    data = [int(input()) for _ in range(n)]
    print(minimum_result(n, k, data))


if __name__ == '__main__':
    solution()