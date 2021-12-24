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

    int ans = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return -1;
        int l = 1 + dfs(root->left);
        int r = 1 + dfs(root->right);
        
        ans =max(ans,l+r);
        return max(l,r);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x = dfs(root);
        return ans;
    }
};