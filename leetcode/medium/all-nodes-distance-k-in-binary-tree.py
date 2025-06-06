from collections import deque, defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        q = deque([root])
        d = defaultdict(list)

        while q:
            curr = q.popleft()

            for child in [curr.left, curr.right]:
                if child:
                    q.append(child)
                    d[curr.val].append(child.val)
                    d[child.val].append(curr.val)

        ans = []
        visited = {}
        q = deque([(target.val, 0)])
        while q:
            curr, v = q.popleft()
            visited[curr] = True
            if v == k:
                ans.append(curr)
                continue

            for next in d[curr]:
                if next not in visited:
                    q.append((next, v + 1))
        return ans
