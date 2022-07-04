from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        q = deque()
        if root:
            q.append(root)
        
        while q:
            cur = q.popleft()
            if cur.val == val:
                return cur
            if cur.val > val and cur.left:
                q.append(cur.left)
            elif cur.right:
                q.append(cur.right)
                
        return None
            
