def binary_search(n, c, data):
    data = sorted(data)
    start = 1
    end = data[-1] - data[0]
    ans = 0

    while start <= end:
        mid = (start + end) // 2
        cnt = 1
        prev = data[0]
        for i in range(1, n):
            if data[i] - prev >= mid:
                cnt += 1
                prev = data[i]
        
        if cnt >= c:
            ans = max(mid, ans)
            start = mid + 1
        else:
            end = mid - 1
    return ans


def solution():
    n, c = map(int, input().split())
    data = [int(input()) for _ in range(n)]
    print(binary_search(n, c, data))


if __name__ == '__main__':
    solution()