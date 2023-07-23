# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        q = deque()
        ans = 0
        if root:
            q.append((root, 1))

        while q:
            pt, count = q.popleft()
            ans = max(ans, count)

            if pt.left:
                q.append((pt.left, count + 1))
            if pt.right:
                q.append((pt.right, count + 1))

        return ans
