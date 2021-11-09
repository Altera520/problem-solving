def parametric_search(m, data, end):
    def cut(data, h):
        ans = 0
        for elem in data:
            if elem >= h:
                ans += elem // h
        return ans

    start = 1
    ans = 0

    while start <= end:
        h = (start + end) // 2
        if cut(data, h) >= m:
            ans = max(ans, h)
            start = h + 1
        else:
            end = h - 1
    return ans


def solution():
    n, m = map(int, input().split())
    data = []
    end = 0
    for _ in range(n):
        data.append(int(input()))
        end = max(data[-1], end)

    print(parametric_search(m, data, end))


if __name__ == '__main__':
    solution()