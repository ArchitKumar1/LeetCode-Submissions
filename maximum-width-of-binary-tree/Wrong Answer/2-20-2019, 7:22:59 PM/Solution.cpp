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
    int l = 0;
    int r = 0;
    void dfs(TreeNode* root ,int left,int right){
        if(root==NULL)
            return ;
        l=max(left,l);
        r=max(right,l);
        dfs(root->left,left+ 1,right);
        dfs(root->right,left,right+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0,0);
        return r+l;
    }
};