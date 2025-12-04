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
        vector<vector<int>> v;
        queue<pair<TreeNode*, int>> q; 
        if(root) q.push({root, 0}); 
        while(!q.empty()){
            auto p = q.front().second; 
            root = q.front().first; 
            q.pop(); 
            if(root->left)q.push({root->left, p+1}); 
            if(root->right)q.push({root->right, p+1}); 
            if(p == v.size()) v.push_back({}); 
            v[p].push_back(root->val);  
        }
        return v; 
    }
};

