from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []
        
        def order(n, tmp):
            tmp.append(str(n.val))
                
            if n.left is not None:
                order(n.left, tmp)
            if n.right is not None:
                order(n.right, tmp)
            
            # is leaf
            if n.left is None and n.right is None:
                ans.append('->'.join(tmp))
                
            tmp.pop()
            
        order(root, [])
        return ans
        
