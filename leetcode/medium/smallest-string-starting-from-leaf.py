from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        q = deque([(root, '')])
        d = {}
        leafs = []
        while q:
            cur, prev = q.popleft()
            d[cur] = chr(cur.val + ord('a')) + prev
            tmp = False
            
            for child in [cur.left, cur.right]:
                if not child:
                    continue
                q.append((child, d[cur]))
                tmp = True
            if not tmp:
                leafs.append(cur)
        
        ans = d[leafs[0]]
        for leaf in leafs:
            ans = min(ans, d[leaf])
            
        return ans
