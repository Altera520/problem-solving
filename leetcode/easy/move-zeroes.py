class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        pt = 0
        for k, v in enumerate(nums):
            if v != 0:
                nums[k] = 0
                nums[pt] = v
                pt += 1
        
