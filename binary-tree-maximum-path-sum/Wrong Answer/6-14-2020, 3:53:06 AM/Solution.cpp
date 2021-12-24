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
    
    int fans = 0;
    
    
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int val = root->val;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        fans = max(fans,val + left + right );
        
        return max(0,max(val + left,val+right));
        
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return fans;
    }
};