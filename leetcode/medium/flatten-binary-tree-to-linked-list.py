# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.bef = None

        def travel(node, parent):
            if self.bef != parent:
                self.bef.right = node
                parent.right = None

            self.bef = node
            if node.left:
                travel(node.left, node)
            if node.right:
                travel(node.right, node)


        def move_right(node):
            if node.left:
                node.right = node.left
                node.left = None
            if node.right:
                move_right(node.right)

        if root:
            travel(root, None)
            move_right(root)
