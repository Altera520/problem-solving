LEN = 100001

def prime_list(n):
    sieve = [False, False] + [True] * n
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if sieve[i]:           
            for j in range(i + i, n, i): 
                sieve[j] = False
    return sieve


def solution():
    a, b = map(int, input().split())    
    ans = 0
    memo = {}
    primes = prime_list(LEN)

    for num in range(2, b + 1):
        if primes[num]:
            memo[num] = 1
            continue
        for idx in range(2, num):
            if primes[idx] and num % idx == 0:
                memo[num] = memo[num // idx] + 1
                break

    for num in range(a, b + 1):
        if primes[memo[num]]:
            ans += 1
    print(ans)


if __name__ == '__main__':
    solution()