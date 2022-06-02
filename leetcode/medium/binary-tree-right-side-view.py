from collections import defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        d = defaultdict(list)
        def traversal(pt, depth):
            if not pt:
                return
            next_depth = depth + 1
            traversal(pt.left, next_depth)
            d[depth].append(pt.val)
            traversal(pt.right, next_depth)
            
        traversal(root, 0)    
        return [d[k][-1] for k in sorted(d.keys())]
