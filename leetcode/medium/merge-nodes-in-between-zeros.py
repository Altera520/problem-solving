# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def delete(prev, cur):
            prev.next = pt.next
            
        head = ListNode(next = head)
        prev = head
        pt = head.next
        flag = False
        
        while pt:
            if pt.val == 0:
                delete(prev, pt)
            elif pt.next and pt.next.val != 0:
                pt.next.val += pt.val
                delete(prev, pt)
            else:
                prev = pt
            pt = pt.next
            
        return head.next
