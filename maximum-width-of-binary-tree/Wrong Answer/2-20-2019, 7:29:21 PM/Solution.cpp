// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int mi = 1 << 30;
    int ma = - 1 << 29;
    void dfs(TreeNode* root ,int d){
        if(root==NULL)
            return ;
        ma=max(ma,d);
        mi=min(mi,d);
        dfs(root->left,d - 1);
        dfs(root->right,d + 1 );
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0);
        return ma -mi;
    }
};