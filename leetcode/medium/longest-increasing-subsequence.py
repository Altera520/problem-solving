class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        d = {}
        answer = 1
        sz = len(nums) - 1
        
        for i in range(sz, -1, -1):
            candidate = 0
            for j in range(i + 1, sz + 1):
                if nums[j] > nums[i]:
                    candidate = max(d[j], candidate)
            d[i] = candidate + 1
            answer = max(answer, d[i])
        return answer


