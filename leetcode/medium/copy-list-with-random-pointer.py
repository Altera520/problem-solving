from collections import deque

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        tmp = {-1: None}
        q = []
        
        pt = head
        
        while pt:
            tmp[pt] = Node(pt.val, pt.next, pt.random)
            q.append(pt)
            pt = pt.next
        
        head = pt = Node(-1)
        nvl = lambda v: v if v else -1
        
        for node in q:
            if node is None:
                continue
            tmp[node].next = tmp[nvl(tmp[node].next)]
            tmp[node].random = tmp[nvl(tmp[node].random)]
            pt.next = tmp[node]
            pt = pt.next
        
        return head.next


