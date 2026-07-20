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
    void preorderTraversal(TreeNode* root,vector<int> &soln){
        if(root==NULL)
            return ;
        soln.emplace_back(root->val);
        if(root->left)
            preorderTraversal(root->left,soln);
        if(root->right)
            preorderTraversal(root->right,soln);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> soln;
        preorderTraversal(root,soln);
        return soln;
    }
};