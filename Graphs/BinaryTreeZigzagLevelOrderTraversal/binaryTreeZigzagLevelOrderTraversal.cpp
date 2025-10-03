/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> nodes;
        vector<vector<int>> result {}; 
        
        if(root) {
            nodes.push_back(root);  
            result.push_back({}); 
        }
        else return {} ;
        int size = 1;
        bool left_right = 1; 
        while(!nodes.empty()){



            //IF left_right = 0; 
            //push front from right to left
            //take front

            // if left_right = 1
            //push back from left to right
            //take back

            
            if(!size){
                result.push_back({}); 
                size = nodes.size();
                left_right^=1; 
            }
            TreeNode* cur = !left_right ? nodes.front() : nodes.back(); 
            --size; 
            result[result.size()-1].push_back(cur->val);
            if(!left_right) nodes.pop_front();
            else nodes.pop_back();  
            if(!left_right){
                if(cur->right) nodes.push_back(cur->right);
                if(cur->left) nodes.push_back(cur->left);
            }
            else{
                if(cur->left) nodes.push_front(cur->left);
                if(cur->right) nodes.push_front(cur->right);
            }
            
        } 
        return result; 
        
    }
};
