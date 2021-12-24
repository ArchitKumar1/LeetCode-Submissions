// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    int fans = 0;
    
    void solve(TreeNode* root,vector<int>cnt,int o,int e){
        if(!root) return;
        
        int val = root->val;
        if(++cnt[val] %2 == 0) o--,e++;
        else o++,e--;  
        
        if(root->left == NULL && root->right == NULL  &&( o == 0 || o == 1))fans += 1;        
        solve(root->left,cnt,o,e);
        solve(root->right,cnt,o,e);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root,vector<int>(10,0),0,10);
        return fans;
    }
};