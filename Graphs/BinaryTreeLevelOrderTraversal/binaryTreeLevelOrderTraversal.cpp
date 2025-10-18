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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> nodes; 
        vector<vector<int>> result {}; 
        
        if(!root) return {}; 
        else result.push_back({root->val});  
        if(root->left) nodes.push({root->left, 1});
        if(root->right) nodes.push({root->right, 1});
        int current_level = 0; 
        while(!nodes.empty()){
            TreeNode* cur = nodes.front().first; 
            int level = nodes.front().second; 
            if(level > current_level){
                result.push_back({}); 
                current_level = level;
            }
            result[result.size()-1].push_back(cur->val);
            nodes.pop(); 
            if(cur->left) nodes.push({cur->left, level+1});
            if(cur->right) nodes.push({cur->right, level+1});
            
        } 
        return result; 
        
    }
};