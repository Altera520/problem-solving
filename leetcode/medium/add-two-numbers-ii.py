# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        def length(pt):
            c = 0
            while pt:
                c += 1
                pt = pt.next
            return c
        
        def fill_zero(pt, c):
            for _ in range(c):
                pt = ListNode(next=pt)
            return pt
        
        length1, length2 = (length(l1), length(l2))
        diff = abs(length1 - length2)
        if length1 > length2:
            l2 = fill_zero(l2, diff)
        else:
            l1 = fill_zero(l1, diff)
        
        def calc(pt1, pt2):
            if not pt1:
                return None, 0
            dst, val = calc(pt1.next, pt2.next)
            tmp = pt1.val + pt2.val + val
            return ListNode(tmp % 10, dst), tmp // 10
        
        pt, val = calc(l1, l2)
        if val != 0:
            pt = ListNode(val, pt)
        return pt
