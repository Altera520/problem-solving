class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:

        def _to_digit(s):
            return int(s, 2)

        def _to_binary(n, l):
            return '{0:b}'.format(n).rjust(l, '0')

        n = len(nums[0])
        max_digit = _to_digit(n * '1')

        for i in range(0, len(nums)):
            nums[i] = _to_digit(nums[i])

        for i in range(0, max_digit + 1):
            if i not in nums:
                return _to_binary(i, n)
