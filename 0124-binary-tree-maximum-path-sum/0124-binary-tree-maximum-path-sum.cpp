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
    int bfs(TreeNode* root,int &soln){
        if(!root)
            return 0;
        int left=bfs(root->left,soln);
        int right=bfs(root->right,soln);
        if((left+right+root->val)>soln){
            soln=left+right+root->val;
        }
        if((left+root->val)>soln){
            soln=left+root->val;
        }
        if((right+root->val)>soln){
            soln=right+root->val;
        }
        if(root->val>soln)
            soln=root->val;
        return max(max(left,right)+root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        int soln=root->val;
        bfs(root,soln);
        return soln;
    }
};