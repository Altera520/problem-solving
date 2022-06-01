from collections import defaultdict
import operator

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        d = defaultdict(int)
        
        def traversal(pt):
            if not pt:
                return 0
            val = pt.val + traversal(pt.left) + traversal(pt.right)
            d[val] += 1
            return val
        
        traversal(root)
        
        _, highest = max(d.items(), key=operator.itemgetter(1))
        return [k for k, v in d.items() if v == highest]
