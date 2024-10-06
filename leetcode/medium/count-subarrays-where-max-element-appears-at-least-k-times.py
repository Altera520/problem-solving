class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        target = max(nums)
        ans = 0
        st = 0
        ed = -1
        count = 0
        len_nums = len(nums)

        while True:
            if count < k:
                ed += 1
                if ed == len_nums:
                    return ans
                if nums[ed] == target:
                    count += 1
            else:
                if nums[st] == target:
                    count -= 1
                st += 1

            if count == k:
                ans += (len_nums - ed)
            