# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        v = []
        i = 0
        
        def inorder(node, flag):
            nonlocal i
            if not node:
                return

            inorder(node.left, flag)
            if flag:
                v.append(node.val)
            else:
                node.val = v[i]
                i += 1
            inorder(node.right, flag)

        inorder(root, True)
        v.sort()
        inorder(root, False)
