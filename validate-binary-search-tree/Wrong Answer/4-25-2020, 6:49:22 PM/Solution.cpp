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
    int x =0;
    bool solve(TreeNode* root){
        if(root == NULL) return 1;
        bool ok = 1;
        ok &= solve(root->left);
        if(root->val <x ) ok = 0;
        x = root->val;
        ok &= solve(root->right);
        return ok;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root);
    }
};