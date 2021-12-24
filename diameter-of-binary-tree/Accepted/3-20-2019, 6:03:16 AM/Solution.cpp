// https://leetcode.com/problems/diameter-of-binary-tree

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
    int m = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int r = dfs(root->right);
        int l = dfs(root->left);
        m = max(m,r+l);
        return 1 + max(r,l);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return m;
    }
};