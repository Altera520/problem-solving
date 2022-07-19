from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def bfs(root):
            q = deque([(root, 0)])
            while q:
                cur, step = q.popleft()
                if cur == None:
                    continue
                if len(ans) == step:
                    ans.append(cur.val)
                else:
                    ans[step] = max(ans[step], cur.val)
                
                for child in [cur.left, cur.right]:
                    q.append((child, step + 1))  
        bfs(root)
        return ans
