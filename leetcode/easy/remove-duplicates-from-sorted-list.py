# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pt = head
        
        while pt:
            if pt.next and pt.val == pt.next.val:
                pt.next = pt.next.next
                continue
            pt = pt.next
        
        return head
        
