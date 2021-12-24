// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    map<int,int> m1;
    
    void dfs(TreeNode* root){
        if(!root)
            return;
        m1[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        ios_base::sync_with_stdio();
        cin.tie(NULL);
        cout.tie(NULL);
        
        dfs(root);
        int val = 0;
        int m = 0;
        vector<int> ans;
        for(auto x : m1){
            m =max(m ,x.second);
        }
        for(auto x : m1){
            if(x.second == m){
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};