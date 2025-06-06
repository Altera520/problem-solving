# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def travel(node, parent):
            nonlocal ans

            values = [0, 0]
            predicates = [False, False]
            for i, child in enumerate([node.left, node.right]):
                if child:
                    v = travel(child, node)
                    predicates[i] = node.val == child.val
                    if predicates[i]:
                        values[i] = v + 1
                    else:
                        ans = max(v , ans)

            if predicates[0] and predicates[1] and parent.val != node.val:
                return sum(values)
            else:
                if predicates[0] and predicates[1]:
                    ans = max(sum(values), ans)
                return max(values)

        if root:
            ans = max(travel(root, TreeNode(val=1001)), ans)
        return ans
