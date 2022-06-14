class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        pos = [idx for idx, num in enumerate(nums) if num == 1]
        
        for i in range(0, len(pos) - 1):
            if pos[i + 1] - pos[i] - 1 < k:
                return False
        return True
