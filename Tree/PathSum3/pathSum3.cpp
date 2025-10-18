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
    void helper(TreeNode* root, int targetSum, unordered_map<long,int> &diff, int &result, long sum = 0){
        if(diff.find(sum-targetSum) != diff.end())result += diff[sum - targetSum]; 
        if(!root) return; 
        

        diff[sum]++; 
        if(root->left)helper(root->left,targetSum, diff, result, sum+root->left->val); 
        if(root->right)helper(root->right, targetSum, diff, result, sum+root->right->val); 
        diff[sum]--; 
        if(!diff[sum]) diff.erase(sum); 
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> diff ;
        int result = 0; 
        diff[0]++;
        if(root)helper(root, targetSum, diff, result, root->val); 
        return result;
    }
};
