// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        while ((root->val - p->val) * (root->val - q->val) > 0)
            root = p->val < root->val ? root->left : root->right;
        return root;
    }
};