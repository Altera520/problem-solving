from collections import deque

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        window = deque()
        d = {}
        ans = 0
        s = 0
        
        for num in nums:
            if window and num in d:
                ans = max(s, ans)
                while True:
                    val = window.popleft()
                    s -= val
                    del d[val]
                    if val == num:
                        break
            s += num
            d[num] = True
            window.append(num)
        ans = max(s, ans)
            
        return ans
