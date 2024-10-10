class Solution:
    def largestNumber(self, nums: List[int]) -> str:

        def customsort(num1, num2):
            if num1 == num2:
                return 0

            # edge case 1. [34323,3432]
            if num1 + num2 > num2 + num1:
                return 1
            else:
                return -1

        if set(nums) == {0}:
            # edge case 2. [0, 0]
            return '0'

        nums = [str(num) for num in nums]
        return ''.join(sorted(nums, key=functools.cmp_to_key(customsort), reverse=True))