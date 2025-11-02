/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* n = NULL) {
        if(n) return n; 
        if(!root) return NULL; 
        TreeNode* curr = NULL;
        if(root == p || root == q) curr = root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q, n);
        TreeNode* right = lowestCommonAncestor(root->right, p, q, n); 
        if(curr && left || curr && right || left && right) {
            n = root; 
            return n; 
        }
        if(curr) return curr; 
        else if (left) return left; 
        else return right; 
        
    }
};
