class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sz = len(nums)
        
        for i, num in enumerate(nums):
            value = target - num
            
            for j in range(i + 1, sz):
                if nums[j] == value:
                    return [i, j]
        return None
        
