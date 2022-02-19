class Solution:    
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        
        # nCr
        def combination(n, r, index, tmp):
            if r == 0:
                return
            
            # shallow copy
            ans.append(tmp[:])
            
            for i in range(index, n):
                tmp.append(nums[i])
                
                # nC`r-1`
                combination(n, r - 1, i + 1, tmp)
                tmp.pop()
                
        combination(len(nums), len(nums) + 1, 0, [])
        return ans
