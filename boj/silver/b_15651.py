
def permutation(n, m, ans):
    if len(ans) == m:
        print(*ans)
        return
    
    for _ in range(1, n + 1):
        ans.append(_)
        permutation(n, m, ans)
        del ans[-1]


def solution():
    n, m = map(int, input().split())
    ans = []
    permutation(n, m, ans)


if __name__ == '__main__':
    solution()