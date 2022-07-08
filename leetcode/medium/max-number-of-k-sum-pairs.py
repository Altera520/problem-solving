from collections import defaultdict as dd

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        d = dd(int)
        count = 0
        for num in nums:
            d[num] += 1
        
        for num in sorted(nums):
            if d[num] == 0:
                continue
            pair = k - num
            if pair not in d:
                continue
            if d[pair] == 0:
                continue
            if num == pair and d[num] <= 1:
                continue
                
            d[num] -= 1
            d[pair] -= 1
            count += 1
        return count
