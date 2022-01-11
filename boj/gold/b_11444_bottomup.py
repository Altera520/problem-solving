MOD = int(1e9 + 7)


def solution():
    n = int(input()) % MOD
    memo = [0, 1]

    # bottom-up
    for i in range(2, n + 1):
      memo[i] = (memo[i - 1] + memo[i - 2])% MOD

    print(memo[n])


if __name__ == '__main__':
    solution()
