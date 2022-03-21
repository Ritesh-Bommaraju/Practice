/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* temp = head;
        while( temp!= NULL){
            v.push_back(temp);
            temp = temp->next;
        }
        int n = v.size();
        temp = v[k-1];
        ListNode* temp1 = v[n-k];
        int ar = temp->val;
        temp->val = temp1->val;
        temp1->val = ar;
        return head;
        
    }
};