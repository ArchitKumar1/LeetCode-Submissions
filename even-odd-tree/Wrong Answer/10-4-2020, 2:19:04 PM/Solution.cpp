// https://leetcode.com/problems/even-odd-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> d;
    int mxd = 0;
    void dfs(TreeNode* root,int de = 0){
        if(!root) return;
        mxd = max(mxd,de);
        dfs(root->left,de+1);
        d[de].push_back(root->val);
        dfs(root->right,de+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        d.resize(1e6+1);
        bool safe = 1;
        for(int i =1;i<=mxd;i+=2){
            reverse(d[i].begin(),d[i].end());
            for(int j = 1;i<d[i].size();j++){
                safe&= d[i][j] > d[i][j-1];
            }
        }
        return safe;
        
    }
};