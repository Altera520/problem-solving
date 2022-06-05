from collections import deque, defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q = deque([(root, 1)])
        d = defaultdict(int)
        
        while q:
            src, lvl = q.popleft()
            if not src:
                continue
            d[lvl] += src.val
            
            for dst in [src.left, src.right]:
                q.append((dst, lvl + 1))
               
        ans = (1, root.val)
        for k, v in d.items():
            if v > ans[1]:
                ans = (k, v)
        return ans[0]
