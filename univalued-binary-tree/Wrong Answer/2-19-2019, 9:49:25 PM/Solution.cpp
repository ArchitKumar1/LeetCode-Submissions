// https://leetcode.com/problems/univalued-binary-tree

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

    void dfs(TreeNode* root){
        if(root == NULL )
            return ;
        if(root->val !=a){
            ans = 0;
            return ;
        }
        dfs(root->left);
        dfs(root->right);
        
    }
    int a;
    int ans = 1;
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        a = root->val;
        return ans;
    }
};