from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        q = deque([root])
        
        while q:
            cur = q.popleft()
            if not cur:
                break
            if cur.val > val:
                if not cur.left:
                    cur.left = TreeNode(val)
                    break
                q.append(cur.left)
            else:
                if not cur.right:
                    cur.right = TreeNode(val)
                    break
                q.append(cur.right)
        
        return TreeNode(val) if not root else root
