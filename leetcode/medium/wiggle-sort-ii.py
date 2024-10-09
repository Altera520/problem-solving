class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        wiggle_nums = sorted(nums, reverse=True)
        l = len(wiggle_nums)

        major = wiggle_nums[l // 2:]
        minor = wiggle_nums[:l // 2]

        flatten = lambda v: list(itertools.chain(*v))

        for i, v in enumerate(flatten(list(zip(major, minor)))):
            nums[i] = v
        if l % 2:
            nums[-1] = wiggle_nums[-1]