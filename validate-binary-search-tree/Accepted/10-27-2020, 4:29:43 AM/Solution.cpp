// https://leetcode.com/problems/validate-binary-search-tree

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
    long long int  x =-1e18;
    bool ok = 1;
    void solve(TreeNode* root){
        if(root == NULL) return ;
        solve(root->left);
        if(root->val <=x ) ok = 0;
        x = root->val;
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return ok;
    }
};