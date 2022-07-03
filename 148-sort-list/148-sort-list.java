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
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        ListNode node = head;
        while (node != null) {
            if (node.val < min) {
                min = node.val;
            }
            if (node.val > max) {
                max = node.val;
            }
            node = node.next;
        }
        int size = max - min + 1;
        
        int[] array = new int[size];
        node = head;
        while (node != null) {
            array[node.val - min]++;
            node = node.next;
        }
        ListNode result = new ListNode();
        ListNode current = result;
        for (int i = 0; i < size; i++) {
            while (array[i] > 0) {
                node = new ListNode(i + min);
                current.next = node;
                current = node;
                array[i]--;
            }
        }
        
        return result.next;
    }
}