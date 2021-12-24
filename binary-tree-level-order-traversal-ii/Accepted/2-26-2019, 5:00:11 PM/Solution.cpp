// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<int> ans[100000];
    int  m = 0; 
    void dfs(TreeNode* root,int depth){
        if(!root) 
            return;
        m = max(m,depth);
        ans[depth].push_back(root->val);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> a;
        if(!root) return a;
        dfs(root,0);
        vector<int> temp;
 
        for(int i=m;i>=0;i--){
            temp.clear();
            for(auto c: ans[i]){
                temp.push_back(c);
            }
            a.push_back(temp);
        }
        return a;
    }
};