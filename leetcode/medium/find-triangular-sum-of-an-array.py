class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while True:
            sz = len(nums)
            if sz == 1:
                break
            for i in range(1, sz):
                nums[i - 1] = (nums[i - 1] + nums[i]) % 10
            nums.pop()
        return nums[0]
