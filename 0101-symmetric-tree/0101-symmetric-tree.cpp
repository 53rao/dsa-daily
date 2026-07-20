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
    void bfs1(TreeNode* root,vector<int> &soln){
        if(!root){
            soln.emplace_back(-101);
            return ;
        }
        soln.emplace_back(root->val);
        bfs1(root->left,soln);
        
        bfs1(root->right,soln);
    }

    void bfs2(TreeNode* root,vector<int> &soln){
        if(!root){
            soln.emplace_back(-101);
            return ;
        }
        soln.emplace_back(root->val);
        bfs2(root->right,soln);
        
        bfs2(root->left,soln);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        if(!root->left&&!root->right)
            return true;
        if(!root->left||!root->right)
            return false;
        vector<int> one;
        vector<int> two;
        bfs1(root->left,one);
        bfs2(root->right,two);
        
        return one==two;
    }
};