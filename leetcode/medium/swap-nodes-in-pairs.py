# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pt = head
        tmp = 0
        
        while pt is not None:
            if pt.next is None:
                break
            tmp = pt.val
            pt.val = pt.next.val
            pt.next.val = tmp
            pt = pt.next.next
            
        return head
