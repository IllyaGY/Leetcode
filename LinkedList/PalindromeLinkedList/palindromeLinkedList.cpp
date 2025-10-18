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
    bool isPalindrome(ListNode* head) {
        int i = 0;
        ListNode* ctr = head; 
        while(ctr){ 
            i++; 
            ctr = ctr->next; 
        }
        ctr = head; 
        i = i / 2 + i%2; 
        while(i>0){
            i--; 
            ctr=ctr->next; 
        }
        ListNode* prev = NULL; 
        while(ctr){
            ListNode* temp = ctr->next;
            ctr->next = prev;
            prev = ctr;  
            ctr = temp; 
        }
        ctr = prev; 
        while(ctr){
            if(head->val != ctr->val) return 0; 
            head=head->next; 
            ctr=ctr->next; 
        }
        return 1; 
    }
};
