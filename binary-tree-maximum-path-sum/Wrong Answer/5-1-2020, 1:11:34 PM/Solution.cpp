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
    int ans = -1e9;
    
    int dfs(TreeNode* root){
        if(root== NULL) return 0;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        int v =root->val;
        ans = max(ans,v+max({0,l,r,l+r}));
        
        return max(r+v,l+v);
    
    }
    int maxPathSum(TreeNode* root) {
        int garbage = dfs(root);
        return ans;
        
    }
};