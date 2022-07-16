"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        
        def link(src, dst):
            if dst:
                dst.prev = src
            src.next = dst
        
        def flat(head):
            pt = head
            tail = head
            while pt:
                if pt.child:
                    src, dst = flat(pt.child)
                    link(dst, pt.next)
                    link(pt, src)
                    pt.child = None
                    pt = dst.next
                    tail = dst.next if dst.next else dst
                    continue
                
                if pt.next:
                    tail = pt.next
                pt = pt.next
            return (head, tail)
        
        return flat(head)[0]
