from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        q = deque([(root, [root])])
        
        def to_number(path):
            base = 1
            val = 0
            for node in path[-1::-1]:
                val += node.val * base
                base *= 10
            return val
            
        ans = 0
        while q:
            cur, path = q.popleft()
            is_leaf = True
            for child in [cur.left, cur.right]:
                if not child:
                    continue
                q.append((child, path[:] + [child]))
                is_leaf = False
        
            if is_leaf:
                ans += to_number(path)
        return ans
