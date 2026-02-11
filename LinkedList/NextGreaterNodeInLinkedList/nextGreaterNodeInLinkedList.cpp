class Solution {
public:
    
    void helper(vector<int> &r, ListNode* head, stack<pair<int,int>>& s, int ctr = 1){
        if(!head) return; 
        while(!s.empty() && head->val > s.top().first){
            r[s.top().second] = head->val ; 
            s.pop(); 
        }
        r.push_back(0); 
        s.push({head->val, ctr - 1});
        helper(r, head->next, s, ctr+1); 
        
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> r; 
        stack<pair<int, int>> s; 
        helper(r, head,s);
        return r; 
    }
};
