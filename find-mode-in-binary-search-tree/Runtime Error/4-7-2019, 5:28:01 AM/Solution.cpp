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
        dfs(root);
        int val = 0;
        int m = 0;
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto x : m1){
            pq.push({x.second,x.first});
        }
        pair<int,int> p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            if(temp.first == p.first){
                ans.push_back(temp.second);
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};