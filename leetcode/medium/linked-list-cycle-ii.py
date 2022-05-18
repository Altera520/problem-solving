# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pt = head
        tmp = {}
        
        while pt:
            if pt in tmp:
                return pt
            tmp[pt] = 0
            pt = pt.next
        return None
