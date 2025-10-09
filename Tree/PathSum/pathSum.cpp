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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0; 
        int v = (targetSum-root->val);
        if(!root->left && !root->right && !v) return 1; 
        return (root->right ? hasPathSum(root->right, v): 0) || (root->left ? hasPathSum(root->left,v ) : 0); // USE || To avoid more recursion if the left side already return true
    }
};
