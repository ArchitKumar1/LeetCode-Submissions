// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int  m = INT_MIN;
    int dfs1(TreeNode* root){
       if(!root)return 0;
        int l = max(0,dfs1(root->left));
        int r = max(0,dfs1(root->right));
        m = max(m,l+r+root->val);
        return max(l,r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        dfs1(root);
        return m;
    }
};