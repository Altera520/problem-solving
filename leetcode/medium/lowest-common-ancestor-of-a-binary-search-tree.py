# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ans = 0
        
        def get_path(v):
            pt = root
            path = []

            while True:
                path.append(pt.val)
                if pt.val == v:
                    return path
                
                if v < pt.val:
                    pt = pt.left
                else:
                    pt = pt.right
            return path
            
        p_path = get_path(p.val)
        q_path = get_path(q.val)

        i, j = 0, 0
        while True:
            if p_path[i] != q_path[j]:
                if i > j:
                    return TreeNode(val=p_path[j])
                if i < j:
                    return TreeNode(val=q_path[i])
                return TreeNode(val=p_path[i - 1])

            if i != len(p_path) - 1:
                i += 1
            if j != len(q_path) - 1:
                j += 1
