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
    bool ispal(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        string s;
        while(head != NULL){
            s+=to_string(head->val);
            head = head->next;
        }
        if(ispal(s)){
            return true;
        }
        else{
            return false;
        }
    }
};