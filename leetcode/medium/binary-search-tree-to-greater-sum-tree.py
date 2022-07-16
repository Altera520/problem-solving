# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        v = 0
        def postorder(root):
            nonlocal v
            if not root:
                return 0
            postorder(root.right)
            root.val += v
            v = root.val
            postorder(root.left)
            
        postorder(root)
        return root
