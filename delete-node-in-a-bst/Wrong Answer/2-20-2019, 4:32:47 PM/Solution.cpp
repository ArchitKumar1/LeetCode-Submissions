// https://leetcode.com/problems/delete-node-in-a-bst

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
    int val;
    void dfs( TreeNode* &root){
        if(root == NULL)
            return;
        if(root->right){
            if(root->right->val == val){
                TreeNode* L = root->right->left;
                TreeNode* R = root->right->right;
                root->right == NULL;
                if(root->right->right){
                    root->right = R;
                    root->right->left = L;
                }
                else if(root->right->right){
                    root->right = L;
                    root->right->right = R;
                }
                return ;
            }
    
        }
        if(root->left){
            if(root->left->val == val){
                TreeNode* L = root->left->left;
                TreeNode* R = root->left->right;
                root->left == NULL;
                if(root->left->right){
                    root->left = R;
                    root->left->left = L;
                }
                else if(root->left->right){
                    root->left = L;
                    root->left->right = R;
                }
                return ;
            }
        }    
        if(root->val == val) {
            root = NULL;
            return ;
        }
        dfs(root->left);
        dfs(root->right);
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        val = key;
        dfs(root);
        return root;
        
    }
};