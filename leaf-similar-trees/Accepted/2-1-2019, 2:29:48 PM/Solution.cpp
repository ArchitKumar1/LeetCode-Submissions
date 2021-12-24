// https://leetcode.com/problems/leaf-similar-trees

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
    vector<int> v1;
    vector<int> v2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1,v1);
        dfs(root2,v2);
        
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
    void dfs(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        else if(root->left==NULL && root->right == NULL) v.push_back(root->val);
        dfs(root->left,v);
        dfs(root->right,v);
    }
};