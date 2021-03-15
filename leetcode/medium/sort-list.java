/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        Queue<ListNode> heap = new PriorityQueue<>((src, dest) -> {
            int result = 0;
            if(src.val > dest.val) result = 1;
            else if(src.val < dest.val) result = -1;
            return result;
        });
        ListNode node = new ListNode();
        
        while(head != null) {
            heap.add(head);
            head = head.next;
        }
        
        head = node;
        while(heap.size() != 0) {
            node.next = heap.poll();
            node = node.next;
        }
        node.next = null;
        
        return head.next;
    }
}