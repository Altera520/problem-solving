class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        pt = 0
        for loc, num in enumerate(nums):
            if num != 0:
                nums[pt] = num
                pt += 1
            if loc != pt - 1:
                nums[loc] = 0
        
