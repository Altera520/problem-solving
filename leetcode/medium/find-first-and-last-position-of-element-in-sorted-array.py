class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        st = float("inf")
        ed = -1

        def bsearch(low, high):
            nonlocal st
            nonlocal ed

            while low <= high:
                mid = (low + high) // 2

                if nums[mid] < target:
                    low = mid + 1
                    continue
                if nums[mid] > target:
                    high = mid - 1
                    continue
                if nums[mid] == target: 
                    st = min(st, mid)
                    ed = max(ed, mid)
                    
                    bsearch(low, mid - 1)
                    bsearch(mid + 1, high)
                    break

        bsearch(0, len(nums) - 1)
        if st == float('inf'):
            st = -1

        return (st, ed)

