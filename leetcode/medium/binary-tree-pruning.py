# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        def prune(node):
            if node is None:
                return None

            l, r = prune(node.left), prune(node.right)
            if not l:
                node.left = None
            if not r:
                node.left = None
            
            return node.val == 1 or l or r

        return root if prune(root) else None