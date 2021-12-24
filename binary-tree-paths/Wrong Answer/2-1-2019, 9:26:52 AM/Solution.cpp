// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> s1;
        string curr;
        if(root==NULL) return s1;
        else{
            char a=root->val+ '0';
            curr=curr+a;
        }
        dfs(root,s1,curr);
        return s1;
    }
    void dfs(TreeNode* root,vector<string> &s1,string curr){
        if(root->right==NULL and root->left==NULL) {
            s1.push_back(curr);
        }
        if(root->left){
            char a=root->left->val+'0';
            string x=to_string(root->left->val);
            string s="->"+x;
            dfs(root->left,s1,curr+s);
            
        }
        if(root->right){
            char a=root->right->val+'0';
            string x=to_string(root->right->val);
            string s="->"+x;
            dfs(root->right,s1,curr+s);
        }
        
        
    }
};