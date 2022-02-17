from collections import defaultdict

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        dic = defaultdict(int)
        
        for num in nums:
            dic[num] += 1
            
        return [k for k, v in dic.items() if v == 1]
            
