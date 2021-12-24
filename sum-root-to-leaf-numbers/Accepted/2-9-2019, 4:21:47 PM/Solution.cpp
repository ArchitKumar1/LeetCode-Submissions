// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int total=0;
    void dfs(TreeNode* root, int sum){
        if(root == NULL ) return ;
        
        sum=sum*10;
        sum=sum+root->val;
        if(root->left ==NULL and root->right == NULL )total+=sum;
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return total;
    }
};