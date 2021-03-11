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
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sum = new ListNode();
        ListNode ans = sum;
        int carry = 0;
        
        while(l1 != null || l2 != null || carry != 0) {
            int val1 = 0;
            int val2 = 0;
            int result = 0;
            
            if(l1 != null) {
                val1 = l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                val2 = l2.val;
                l2 = l2.next;
            }
            
            result = val1 + val2 + carry;
            
            sum.next = new ListNode();
            sum = sum.next;
            sum.val = result % 10;
            carry = result / 10;
        }
        
        return ans.next;
    }
}