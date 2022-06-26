from collections import defaultdict, deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans = defaultdict(list)
        q = deque([(root, False, 0)])
        
        while q:
            node, flag, lvl = q.popleft()
            if lvl % 2 == 1:
                ans[lvl].insert(0, node.val)
            else:
                ans[lvl].append(node.val)
            childs = [node.left, node.right]
            for child in childs:
                if not child:
                    continue
                q.append((child, not flag, lvl + 1))
        return ans.values()
        
