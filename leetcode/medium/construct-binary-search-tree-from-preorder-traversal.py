# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        inorder = sorted(preorder)
        
        def make(st, ed, preorder):
            for i in range(st, ed):
                if inorder[i] != preorder[0]:
                    continue
                node = TreeNode(preorder[0])
                node.left = make(st, i, preorder[1 : i - st + 1])
                node.right = make(i + 1, ed, preorder[i - st + 1:])
                return node
            return None
        
        return make(0, len(preorder), preorder)
        
        #[8, 5, 1, 7, 6, 9, 10, 11, 12]
        #[1, 5, 6, 7, 8, 9, 10, 11, 12]
        #[1, 5, 6, 7] [9, 10, 11, 12]
        #[1] [6,7] [9, 10, 11, 12]
        #[1] [6] [7]
