from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []

        if root:
            q = deque([(root, [root.val], root.val)])

            while q:
                curr, path, v = q.popleft()

                if curr.left:
                    q.append((curr.left, path + [curr.left.val], v + curr.left.val))
                if curr.right:
                    q.append((curr.right, path + [curr.right.val], v + curr.right.val))

                if not curr.left and not curr.right and v == targetSum:
                    ans.append(path)
        return ans
