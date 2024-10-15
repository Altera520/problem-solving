from collections import deque, defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        table = defaultdict(int)
        q = deque([(root, 1)])
        while q:
            cur, lv = q.popleft()
            table[lv] += cur.val

            for child in [cur.left, cur.right]:
                if child:
                    q.append((child, lv + 1))  

        lv_sums = sorted(table.values(), reverse=True)

        return lv_sums[k - 1] if len(lv_sums) >= k else -1