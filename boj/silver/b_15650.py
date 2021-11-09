
def combination(n, m, ans, visit):
    if len(ans) == m:
        print(*ans)
        return
    
    for _ in range(1, n + 1):
        if len(ans) > 0 and  _ < ans[-1]:
            continue
        if visit[_]: 
            continue
        ans.append(_)
        visit[_] = True
        combination(n, m, ans, visit)
        del ans[-1]
        visit[_] = False


def solution():
    n, m = map(int, input().split())
    visit = [False for _ in range(n + 1)]
    ans = []
    combination(n, m, ans, visit)


if __name__ == '__main__':
    solution()