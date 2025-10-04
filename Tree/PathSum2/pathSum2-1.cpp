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
    void helper(TreeNode* root, int targetSum, vector<int>& summed, vector<vector<int>>& result){
        if(!root) return; 
        if(!root->left && !root->right){
            if(!targetSum) result.push_back(summed); 
            return; 
        }
        if(root->left) {
            summed.push_back(root->left->val); 
            helper(root->left, targetSum-root->left->val, summed, result); 
            summed.pop_back(); 
        }
        if(root->right) {
            summed.push_back(root->right->val); 
            helper(root->right, targetSum-root->right->val, summed, result); 
            summed.pop_back(); 
        }
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result; 
        vector<int> summed; 
        if(root){
            summed.push_back(root->val); 
            helper(root, targetSum-root->val,summed, result); 
            summed.pop_back(); 
        }
        return result; 
    }
};
