// https://leetcode.com/problems/invert-binary-tree

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
    void dfs(TreeNode* root){
        if( root == NULL)
            return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->right = l;
        root->left = r;
        dfs(root->right);
        dfs(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};