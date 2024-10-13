class Solution:
    def integerReplacement(self, n: int) -> int:
        # loop 사용 시, Memory Limited Exception
        # memo = {}
        # memo[1] = 0

        # for i in range(2, n + 1):
        #     if i % 2 == 0:
        #         memo[i] = memo[i // 2] + 1
        #     else:
        #         memo[i + 1] = memo[(i + 1) // 2] + 1
        #         memo[i] = min(memo[i + 1], memo[i - 1]) + 1

        def f(n):
            if n <= 1:
                return 0
            
            if n % 2 == 0:
                return f(n // 2) + 1
            else:
                return min(f(n + 1), f(n - 1)) + 1

        return f(n)