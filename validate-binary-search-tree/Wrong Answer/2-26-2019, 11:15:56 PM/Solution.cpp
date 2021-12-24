// https://leetcode.com/problems/validate-binary-search-tree

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
    bool ans = 0;
    void dfs(TreeNode* root){
        if(!root)
            return ;
        if(root->right && root->left)  {
           if((root->left && root->left->val > root->val ) || (root->right && root->right->val <root->val)){
            ans = 1;
            return;
            }
        }
        else{ans = 1;return;}
           
         dfs(root->left);
         dfs(root->right);
    }
    bool isValidBST(TreeNode* root,int t = 0) {
        dfs(root);
        return(ans == 0) ? 0 : 1;
    }
};