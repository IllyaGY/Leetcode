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
    void h(TreeNode* node, vector<int> & r){
        if(!node) return; 
        h(node->left, r); 
        h(node->right, r); 
        r.push_back(node->val); 

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> r; 
        h(root, r); 
        return r; 
    }
};
