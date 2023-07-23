class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        d = {
            0: 0
        }

        for n in range(1, amount + 1):
            tmp = [d[n - c] for c in coins if n >= c and d[n - c] != -1]
            d[n] =  -1 if len(tmp) == 0 else min(tmp) + 1

        return d[amount]
