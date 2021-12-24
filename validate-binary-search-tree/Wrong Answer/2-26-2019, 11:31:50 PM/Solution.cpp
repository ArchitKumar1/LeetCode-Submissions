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
    int inf = 1<<30;
    bool ans = 0;
    void dfs(TreeNode* root){
        if(!root)
            return ;
        if(root->left && root->left->val > root->val) ans = 1;
        if(root->right && root->right->val < root->val) ans = 1;
        dfs(root->right);
        dfs(root->left);
        
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return (ans == 0) ? 1 : 0;
    }
};