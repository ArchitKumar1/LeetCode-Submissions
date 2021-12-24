// https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree

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
    bool dfs(TreeNode* root, vector<int>& arr,int pos){
        if(root == NULL){
            return( pos == arr.size());
        }
        if(pos == arr.size()){
            return (root->left == NULL && root->right == NULL);
        }
        if(root->val == arr[pos]){
            return dfs(root->left,arr,pos + 1) || dfs(root->right,arr,pos+1) ;
        }else{
            return 0;
        }
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
       return dfs(root,arr,0);
        
    }
};