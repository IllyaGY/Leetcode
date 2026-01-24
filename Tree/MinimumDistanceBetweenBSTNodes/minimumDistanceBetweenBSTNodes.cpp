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
    void h (vector<int>& v, TreeNode* root){
        if(!root) return; 
        v.push_back(root->val); 
        h(v, root->left); 
        h(v, root->right); 
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v; 
        h(v, root); 
        sort(v.begin(), v.end()); 
        int mn = INT_MAX; 
        for(int i = 1; i < v.size(); i++) mn = min(mn, v[i] - v[i-1]); 
        return mn; 
    }
};