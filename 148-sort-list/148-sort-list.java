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
        ListNode dm = new ListNode(0);  
        while(head != null){   
            ListNode temp = dm;
            ListNode next = head.next;
            while(temp.next != null && temp.next.val < head.val)
            temp = temp.next;
            head.next = temp.next;    
            temp.next = head;
            head = next;
        }
        return dm.next;
        
    }
}