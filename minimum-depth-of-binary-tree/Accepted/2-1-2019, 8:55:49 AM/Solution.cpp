// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int d=0;
    int minDepth(TreeNode* root) {

        if(root==NULL) return 0;
        else if(root->right==NULL  && root->left==NULL )return 1;
        else if(root->left!=NULL && root->right== NULL)
            return minDepth(root->left)+1;
        else if(root->right!=NULL && root->left==NULL)
            return minDepth(root->right)+1;
        else return min(minDepth(root->left),minDepth(root->right))+1;
    }
    
};