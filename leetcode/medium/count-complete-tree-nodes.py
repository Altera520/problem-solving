from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        answer = 0
        if not root:
            return answer
        q = deque([root])
        
        while q:
            current = q.popleft()
            answer += 1
            
            for next in [current.left, current.right]:
                if not next:
                    continue
                q.append(next)
        return answer
