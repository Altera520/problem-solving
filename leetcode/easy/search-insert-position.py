class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        answer = 0
        
        while start <= end:
            mid = (start + end) // 2
                
            if nums[mid] == target:
                answer = mid
                break
            
            if nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
                
            if start >= end:
                answer = mid + 1 if nums[mid] < target else mid
            
        return answer
            
