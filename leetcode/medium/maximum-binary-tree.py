# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        
        def build(st, ed):
            if st >= ed:
                return None
            
            candidate = st
            for i in range(st, ed):
                if nums[i] > nums[candidate]:
                    candidate = i
            
            return TreeNode(nums[candidate], build(st, candidate), build(candidate + 1, ed))
        
        return build(0, len(nums))
            
