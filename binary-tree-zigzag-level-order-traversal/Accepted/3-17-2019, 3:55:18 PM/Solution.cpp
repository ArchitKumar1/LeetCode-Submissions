// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    int m = 0;
    void dfs(TreeNode* root,vector<vector<int>> &ans,int depth = 0){
        if(!root) return ;
        ans[depth].push_back(root->val);
        m = max(m,depth);
        dfs(root->left,ans,depth+1);
        dfs(root->right,ans,depth+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans(100000);
        if(!root) {
            ans.resize(m);
            return ans;
        }
        dfs(root,ans,0);
        for(int i=1;i<=m;i= i+2){
            reverse(ans[i].begin(),ans[i].end());
        }
        ans.resize(m+1);
        return ans;
    }
};