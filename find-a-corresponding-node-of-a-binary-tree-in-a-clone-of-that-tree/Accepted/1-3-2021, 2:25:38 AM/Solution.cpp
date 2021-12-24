// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

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
    TreeNode* ans,*C,*O,*T;
    
    void dfs(TreeNode* root){
        if(!root) return;
        if(root->val == T->val) ans = root;
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        C = cloned,O = original,T=target;
        dfs(cloned);
        return ans;
    }
};