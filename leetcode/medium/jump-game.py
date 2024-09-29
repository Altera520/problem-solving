class Solution:
    def canJump(self, nums: List[int]) -> bool:
        f = {}
        last = len(nums) - 1
        f[last] = True

        for i in range(last - 1, -1, -1):
            f[i] = False
            if nums[i] >= last - i:
                f[i] = True
            else:
                for j in range(nums[i], -1, -1):
                    f[i] = f[i + j]
                    if f[i]:
                        break
        return f[0]
