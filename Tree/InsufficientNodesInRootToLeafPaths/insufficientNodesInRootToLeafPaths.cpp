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


    TreeNode* sufficientSubset(TreeNode* root, int limit, int sum = 0) {
        if(!root) return NULL; 
        int ct = root->left ? 1 : 0; 
        ct+=root->right ? 1 : 0; 
        if(root->left || root->right){
            root->left = sufficientSubset(root->left, limit, sum+root->val); 
            root->right = sufficientSubset(root->right, limit, sum+root->val); 
        }
        if(!root->left && !root->right){
            if((sum + root->val < limit) || ct) return NULL; 
        }
        return root; 

        
    }
};
