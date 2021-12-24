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
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->right);
        dfs(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        dfs(root);
        return root;
    }
};