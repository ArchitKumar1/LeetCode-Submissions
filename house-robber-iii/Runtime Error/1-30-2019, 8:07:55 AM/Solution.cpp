// https://leetcode.com/problems/house-robber-iii

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
    void dfs(TreeNode* x,int &m){
        if(x->left) {
            x->left->val+=x->val;
            m=max(m,x->left->val);
            dfs(x->left,m);
        }
        if(x->right) {
            x->right->val+=x->val;
            m=max(m,x->right->val);
            dfs(x->right,m);
        }
    }
    int rob(TreeNode* root) {
        int m=0;
        dfs(root,m);
        return m;
    }
};