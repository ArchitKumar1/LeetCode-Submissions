// https://leetcode.com/problems/path-sum-ii

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
    int x;
    vector<vector<int>> v1;
    void dfs(TreeNode* root, int sum,vector<int> temp){
        if(root == NULL) return ;

        
        sum+=root->val;
        temp.push_back(root->val);
        
        
        if(root->left ==NULL && root->right==NULL) if(sum==x) v1.push_back(temp);
        dfs(root->left,sum,temp);
        dfs(root->right,sum,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        x=sum;
        dfs(root,0,temp);
        return v1;
    }
};