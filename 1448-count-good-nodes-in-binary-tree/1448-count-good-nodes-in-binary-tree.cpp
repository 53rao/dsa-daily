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
    void bfs(TreeNode* root,int high,int &soln){
        if(!root)
            return ;
        if(root->val>=high){
            soln++;
            bfs(root->left,root->val,soln);
            bfs(root->right,root->val,soln);
        }
        else{
            bfs(root->left,high,soln);
            bfs(root->right,high,soln);
        }
    }
    int goodNodes(TreeNode* root) {
        int soln=0;
        bfs(root,root->val,soln);
        return soln;
    }
};