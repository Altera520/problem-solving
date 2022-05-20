class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        
        while True:
            value = numbers[left] + numbers[right]
            if value > target:
                right -= 1
                continue
            if value < target:
                left += 1
                continue
            break
            
        return [left + 1, right + 1]
