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
    void inorderTraversal(TreeNode* root,vector<int> &soln){
        if(root==NULL)
            return ;
        
        if(root->left)
            inorderTraversal(root->left,soln);
        soln.emplace_back(root->val);
        if(root->right)
            inorderTraversal(root->right,soln);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> soln;
        inorderTraversal(root,soln);
        return soln;
    }
};