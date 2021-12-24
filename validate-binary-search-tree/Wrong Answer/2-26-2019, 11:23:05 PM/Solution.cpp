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
        if((root->left ==NULL &&  root->right ==NULL) || (root->left && root->right))
        {
            if(root->left && root->right)
                if(root->left->val > root->val || root->right->val < root->val)
                    ans = 1;
        }
        else 
            ans = 1;
        dfs(root->left);
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return (ans == 0) ? 1 : 0;
    }
};