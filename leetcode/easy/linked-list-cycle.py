# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        pt = head
        tmp = {}
        
        while pt:
            if pt in tmp:
                return True
            tmp[pt] = 0
            pt = pt.next
        return False
