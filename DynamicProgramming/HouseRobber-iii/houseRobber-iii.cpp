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

    pair<int,int> helper(TreeNode* root){          
        if(!root) return {0, 0};  //left - prev , right - prev prev
        auto l = helper(root->left);
        auto r = helper(root->right);
        return {max(l.second + r.second + root->val, l.first + r.first), l.first + r.first}; //currect -- prev
       
    }
    int rob(TreeNode* root) {
        auto p = helper(root); 
        return max(p.first, p.second);
        
    }
};
