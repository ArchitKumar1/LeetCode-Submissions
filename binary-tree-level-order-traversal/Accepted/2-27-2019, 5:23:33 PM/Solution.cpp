// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<int> ans[10000];
    int m = -1;
    void dfs(TreeNode* root,int depth){
        if(root == NULL )
            return ;
        ans[depth].push_back(root->val);
        m=max(m,depth);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int >> a;
        if(!root) 
            return a;
        vector<int> temp;
        dfs(root,0);
        for(int i=0;i<=m;i++){
            temp.clear();
            for(auto y: ans[i])
                temp.push_back(y);
            a.push_back(temp);
        }
        return a;
    }
};