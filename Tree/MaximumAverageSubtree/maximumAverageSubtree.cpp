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
    double h(TreeNode* root, double &mx, int& ctr) {
        if(!root) return -1; 
        ctr++; 
        int lc = 0; 
        int rc = 0;
        double left = h(root->left, mx, lc);
        double right = h(root->right, mx, rc); 
        ctr += lc + rc; 
        mx = max((root->val + (left >= 0 ? left : 0) + (right >= 0 ? right : 0))/ctr,mx); 
        
        return root->val + (left >= 0 ? left : 0) + (right >= 0 ? right : 0); 
    }
    double maximumAverageSubtree(TreeNode* root) {
        double mx = 0; 
        int ctr = 0; 
        h(root, mx, ctr); 
        return mx; 
    }
};
