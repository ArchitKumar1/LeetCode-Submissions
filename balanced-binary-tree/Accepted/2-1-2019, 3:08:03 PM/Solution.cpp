// https://leetcode.com/problems/balanced-binary-tree

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return 1;
        if(abs(depth(root->left)-depth(root->right))>1)
            return 0;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root){
        if(root == NULL ) return 0;
        int left=depth(root->left)+1;
        int right=depth(root->right)+1;
        return max(left,right);
    }
};