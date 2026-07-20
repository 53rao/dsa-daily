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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        stack<TreeNode*> st;
        vector<vector<int>> soln;
        st.push(root);
        int flag=1;
        while(st.size()){
            stack<TreeNode*> temp;
            vector<int> vect;
            while(st.size()){
                TreeNode* curr=st.top();
                st.pop();
                vect.emplace_back(curr->val);
                if(flag){
                    if(curr->left)
                        temp.push(curr->left);
                    if(curr->right)
                        temp.push(curr->right);
                }
                else{
                    if(curr->right)
                        temp.push(curr->right);
                    if(curr->left)
                        temp.push(curr->left);
                }
            }
            flag=!flag;
            soln.emplace_back(vect);
            st=temp;
        }
        return soln;
    }
};