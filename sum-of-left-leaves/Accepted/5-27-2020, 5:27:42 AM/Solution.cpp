// https://leetcode.com/problems/sum-of-left-leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root,int dir = 0) {
        int ans= 0 ;
        if(!root) return 0;
        if(!root->left && !root->right && dir == -1) ans += root->val;
        return ans + sumOfLeftLeaves(root->left,-1) + sumOfLeftLeaves(root->right,1);
    }
};