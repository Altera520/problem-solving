
def permutation(n, m, ans):
    if len(ans) == m:
        print(*ans)
        return
    
    for _ in range(1, n + 1):
        if len(ans) > 0 and  _ < ans[-1]:
            continue
        ans.append(_)
        permutation(n, m, ans)
        del ans[-1]


def solution():
    n, m = map(int, input().split())
    permutation(n, m, [])


if __name__ == '__main__':
    solution()