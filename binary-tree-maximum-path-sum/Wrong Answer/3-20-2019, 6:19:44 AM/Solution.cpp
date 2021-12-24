// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int  m = -1 * (1 << 30);
    int dfs1(TreeNode* root){
       if(!root)return 0;
        int l = dfs1(root->left);
        int r = dfs1(root->right);
        m = max(m,l+r+root->val);
        return max(l,r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs1(root);
        return m;
    }
};