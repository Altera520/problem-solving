from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        d = {}
        delete = {}
        for item in to_delete:
            delete[item] = True
        q = deque([(root, None, None)])
        
        while q:
            cur, prev, loc = q.popleft()
            d[cur.val] = (cur, prev, loc)
            if cur.left:
                q.append((cur.left, cur, True))
            if cur.right:
                q.append((cur.right, cur, False))
                
        def remove(prev, loc):
            if loc is None:
                return
            if loc:
                prev.left = None
            else:
                prev.right = None
        
        ans = [root]
        for query in to_delete:
            if query not in d:
                continue
            cur, prev, loc = d[query]
            remove(prev, loc)
            ans.append(cur.left)
            ans.append(cur.right)
                    
        return [pt for pt in ans if pt and pt.val not in delete]
