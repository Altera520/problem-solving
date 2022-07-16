from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def order(root, reverse = False):
            ans = []
            q = deque([root])
            while q:
                cur = q.popleft()
                if not cur:
                    ans.append(cur)
                    continue
                ans.append(cur.val)
                childs = [cur.left, cur.right]
                for child in reversed(childs) if reverse else childs:
                    q.append(child) 
            return ans
        return order(root.left, True) == order(root.right)
