from collections import defaultdict, deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        d = defaultdict(list)
        ans = []
        q = deque([(root, 0)]) if root else None

        while q:
            node, depth = q.popleft()
            d[depth].append(node.val)

            if node.left:
                q.append((node.left, depth + 1))
            if node.right:
                q.append((node.right, depth + 1))
        

        for k in sorted(d.keys(), reverse=True):
            ans.append(d[k])
        return ans
