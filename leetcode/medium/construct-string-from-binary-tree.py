from typing import Literal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:

        def dfs(node, d: Literal["l", "r"]):
            if not node:
                return '()' if d == 'l' else ''

            child = f'{dfs(node.left, "l")}{dfs(node.right, "r")}'
            if child == '()':
                child = ''
                
            v = f'({node.val}{child})'
            return v

        return dfs(root, 'l')[1:-1]

