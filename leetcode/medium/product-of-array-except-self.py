class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = []
        right = []
        ans = []

        acc = 1
        for num in nums:
            acc *= num
            left.append(acc)

        acc = 1
        for num in reversed(nums):
            acc *= num
            right.append(acc)
        right = list(reversed(right))

        # print(left)
        # print(right)

        for i in range(len(nums)):
            l = left[i - 1] if i - 1 >= 0 else 1
            r = right[i + 1] if i + 1 < len(nums) else 1
            ans.append(l * r)
            
        return ans