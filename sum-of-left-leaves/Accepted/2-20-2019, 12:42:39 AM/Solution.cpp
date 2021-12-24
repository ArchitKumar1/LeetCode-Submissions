// https://leetcode.com/problems/sum-of-left-leaves

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
    int sumOfLeftLeaves(TreeNode* root,bool isleft = false) {
        if(root == NULL) return 0;
        if(!root->right && ! root->left) return isleft ? root->val : 0 ;
        return sumOfLeftLeaves(root->left,true) + sumOfLeftLeaves(root->right,false);
    }
};