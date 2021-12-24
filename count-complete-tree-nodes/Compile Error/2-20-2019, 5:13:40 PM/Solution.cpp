// https://leetcode.com/problems/count-complete-tree-nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
        return(1+ countNodes(root->left) + countNodes(root->right));
    }
};