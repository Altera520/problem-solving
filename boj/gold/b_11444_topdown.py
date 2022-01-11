MOD = int(1e9 + 7)


# Top down (memoziation)
def factorial(n, memo):
    if n not in memo:
        memo[n] = (factorial(n - 1, memo) + factorial(n - 2, memo)) % MOD
    
    return memo[n]


def solution():
    n = int(input())
    memo = {0: 0, 1: 1}
    print('%d' % factorial(n, memo))


if __name__ == '__main__':
    solution()
