class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        d = nums[:]
        for i in range(1, len(nums)):
            d[i] = nums[i] + d[i - 1]
        return d
