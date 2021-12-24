// https://leetcode.com/problems/trim-a-binary-search-tree

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
    int L,H;
    
    
    TreeNode* dfs(TreeNode* root){
        if(!root) return NULL;
        
        int V = root->val;
        
        root->left = dfs(root->left);
        root->right = dfs(root->right);

        
        if(V < L){
            return root->right;
        }else if(V > H){
            return root->left;
        }else{
            return root;
        }
        
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        L = low;
        H = high;
        
        return dfs(root);
        
        
    }
};