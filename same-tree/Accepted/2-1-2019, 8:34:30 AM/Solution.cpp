// https://leetcode.com/problems/same-tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return 1;
        else if(p==NULL || q==NULL) return 0;
        else if(p->val!=q->val) return 0;
        return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }
};