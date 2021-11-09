def parametric_search(m, data):
    def cut(data, h):
        ans = 0
        for elem in data:
            # ans += max(elem - h, 0), 이렇게 쓰면 TLE
            if elem > h:
                ans += elem - h
        return ans

    start = 0
    end = max(data)
    ans = 0

    while start <= end:
        h = (start + end) // 2
        if  cut(data, h) >= m:
            ans = max(ans, h)
            start = h + 1
        else:
            end = h - 1
    return ans


def solution():
    n, m = map(int, input().split())
    tree = list(map(int, input().split()))
    print(parametric_search(m, tree))


if __name__ == '__main__':
    solution()