def div(paper, n, x, y, ans):
    v = paper[y][x]

    def is_possible():
        possible = True
        for i in range(y, y + n):
            for j in range(x, x + n):
                possible = (paper[i][j] == v)
                if not possible:
                    return possible
        return possible

    if is_possible():
        ans[v] += 1
    else:
        n //= 2
        d = [(0, n), (n, 0), (0, 0), (n, n)]
        for dx, dy in d:
            div(paper, n, x + dx, y + dy, ans)


def solution():
    paper = []
    n = int(input())
    for _ in range(n):
        paper.append(list(map(int, input().split())))
    ans = [0, 0]
    div(paper, n, 0, 0, ans)
    print(*ans, sep='\n')


if __name__ == '__main__':
    solution()
