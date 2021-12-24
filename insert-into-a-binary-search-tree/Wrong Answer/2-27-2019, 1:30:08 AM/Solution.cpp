// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root->left){
            TreeNode * x = new TreeNode(val);
            TreeNode * o = root->left;
            root->left = x;
            x->left = o;
            return root;
        }
        else{
            TreeNode * x = new TreeNode(val);
            root->left = x;
        }
        return root;
    }
};