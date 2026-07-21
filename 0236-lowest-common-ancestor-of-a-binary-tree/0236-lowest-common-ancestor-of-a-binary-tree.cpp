/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool bfsqueue(TreeNode* root, TreeNode* p,vector<TreeNode*> &s){
        if(!root)
            return false;
         s.push_back(root);
        if(root==p){
            return true;
        }
        else if(bfsqueue(root->left,p,s)||bfsqueue(root->right,p,s))
            return true;
        s.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> s;
        vector<TreeNode*> t;
        bfsqueue(root,p,s);
        bfsqueue(root,q,t);
        TreeNode* soln=NULL;
        int i=0,j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[i]){
                soln=s[i];
                i++;
                j++;
            }
            else
                break;
            
        }
        return soln;
    }
};