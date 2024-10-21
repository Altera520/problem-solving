import math
from collections import namedtuple

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = math.inf
        end = len(nums)

        st, ed, val = (0, 0, nums[0])
        while True:
            if val >= target:
                ans = min(ans, ed - st + 1)
                val -= nums[st]
                st += 1
            else:
                ed += 1
                if ed == end:
                    break
                val += nums[ed]

        return 0 if ans == math.inf else ans