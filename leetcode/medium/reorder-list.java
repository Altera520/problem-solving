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
    
    List<ListNode> list = new ArrayList<>();
    
    public void reorderList(ListNode head) {
        ListNode node = head;
        int start, end;
        
        while(node != null) {
            list.add(node);
            node = node.next;
        }
        
        start = 0;
        end = list.size() - 1;
        node = new ListNode();
        while(start <= end) {
            list.get(start).next = list.get(end);
            node.next = list.get(start);
            node = list.get(end);
            
            start++;
            end--;
        }
        node.next = null;
    }
}