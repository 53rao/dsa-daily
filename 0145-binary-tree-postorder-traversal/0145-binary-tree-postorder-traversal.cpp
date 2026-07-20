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
    void porderTraversal(TreeNode* root,vector<int> &soln){
        if(root==NULL)
            return ;
        
        if(root->left)
            porderTraversal(root->left,soln);
        
        if(root->right)
            porderTraversal(root->right,soln);
        soln.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> soln;
        porderTraversal(root,soln);
        return soln;
    }
};