// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> pos;
    
    void dfs(TreeNode* root){
        if(root== NULL) return;
        dfs(root->right);
        pos.push_back(root->val);
        dfs(root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return pos;
        
        dfs(root->right);
        pos.push_back(root->val);
        reverse(pos.begin(),pos.end());
        return pos;
    }
};