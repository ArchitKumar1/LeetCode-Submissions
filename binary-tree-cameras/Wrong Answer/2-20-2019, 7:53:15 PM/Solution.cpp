// https://leetcode.com/problems/binary-tree-cameras

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
    int cam = 0;
    int odd = 0;
    int even = 0;
    void dfs(TreeNode* root,int depth){
        if(root == NULL)
            return;
        depth% 2 == 0 ? even++ : odd++;
        
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1+max(depth(root->right),depth(root->left));
    }
    int minCameraCover(TreeNode* root) {
        dfs(root,1);
        if(depth(root) == 1)
            return 1;
        if(depth(root) == 2)
            return 1;
        return even;
    }
};