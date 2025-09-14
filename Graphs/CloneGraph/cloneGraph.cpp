/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL; 
        queue<Node*> ngh; 
        unordered_map<uint8_t, Node*> seen; 
        
        Node *head = new Node(node->val);
        seen[node->val] = head; 
        ngh.push(node);
        while(!ngh.empty()) {
            Node *n = seen[ngh.front()->val]; 
            for(auto&i : ngh.front()->neighbors){
                
                if(!seen[i->val]){
                    ngh.push(i); 
                    seen[i->val] = new Node(i->val); 
                }
                n->neighbors.push_back(seen[i->val]); 
                
            }
            ngh.pop(); 
        }
        return head ;
    }
};
