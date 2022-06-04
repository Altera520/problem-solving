from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([(root, 0)])
        ans = (0, root.val)
        
        while q:
            pt, depth = q.popleft()
            if not pt:
                continue
            if ans[0] < depth:
                ans = (depth, pt.val)
            for prev in [pt.left, pt.right]:
                q.append((prev, depth + 1))
        return ans[1]
