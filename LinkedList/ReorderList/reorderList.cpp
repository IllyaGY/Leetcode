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


    void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<ListNode*> s;
        while(temp){
            s.push_back(temp);
            temp = temp->next;
        }
        int j = s.size()-1;
        int i = 0;
        while(i < j-1){
            s[j-1]->next = s[j]->next;
            ListNode* n = s[i]->next;
            s[i]->next = s[j];
            s[i]->next->next = n;
            i++;
            j--;
        }
    }
};
