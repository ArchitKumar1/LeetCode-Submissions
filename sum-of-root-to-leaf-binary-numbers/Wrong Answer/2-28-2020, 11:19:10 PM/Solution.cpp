// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    int fans = 0;
    void dfs(TreeNode* root,int ans = 0) {
        if(!root){
            fans +=ans;
            return ;
        }
        ans = 2*ans + root->val;
        dfs(root->right,ans);
        dfs(root->left, ans);

    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return fans/2;
    }
};