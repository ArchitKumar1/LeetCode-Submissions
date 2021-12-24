// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    int totalsum = 0;
    int mod = 1e9+7;
    long long int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int nodesum = (root->val + dfs(root->left) + dfs(root->right))%mod;
        return nodesum;
    }
    int dfs2(TreeNode* root){
        if(!root) return 0;
        int nodesum = (root->val + dfs2(root->left) + dfs2(root->right))%mod;
        ans = max(ans,(long long)(totalsum - nodesum)*nodesum);
        return nodesum;
    }
    int maxProduct(TreeNode* root) {
        totalsum = dfs(root);
        dfs2(root);
        return ans%mod;
    }
};