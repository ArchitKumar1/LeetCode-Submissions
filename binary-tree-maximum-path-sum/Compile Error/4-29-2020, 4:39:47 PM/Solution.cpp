// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int ans = 0;
    
    int dfs(TreeNode* root){
        if(root== NULL) return -1e9;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(0,max(l,0) + max(r,0) + root->val);
        
        return max(max(max(l,0),max(r,0)) + root->val,0); 
        
    }
    int maxPathSum(TreeNode* root) {
        int garbage = dfs(root);
        
    }
};