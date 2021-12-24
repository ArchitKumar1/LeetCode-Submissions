// https://leetcode.com/problems/increasing-order-search-tree

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
    TreeNode* T,*curr;
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        increasingBST(root->left);
        if(T==NULL){
            T=new TreeNode(root->val);
            curr=T;
        }
        else{
            curr->right=new TreeNode(root->val);
            curr=curr->right;
        }
        increasingBST(root->right);
        return T;
    }
    
};