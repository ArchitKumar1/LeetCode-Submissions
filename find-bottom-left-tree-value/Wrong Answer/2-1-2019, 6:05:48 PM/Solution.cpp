// https://leetcode.com/problems/find-bottom-left-tree-value

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
    int m=0;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL and root->right ==NULL) m=root->val;
        dfs(root->left);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root);
        return m;
    }
};