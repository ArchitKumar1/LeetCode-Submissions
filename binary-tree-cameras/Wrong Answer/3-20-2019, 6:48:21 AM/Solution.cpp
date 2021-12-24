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
    int m = 0;
    bool dfs(TreeNode* root,bool parentcam = 0){
        if(!root) return true;
        bool ok1 = dfs(root->left,0);
        bool ok2 = dfs(root->right,0);
        if(!ok1 && !ok2 && !parentcam){
            m += 1;
            return true;
        }else{
            return false;
        }
    }
    int minCameraCover(TreeNode* root) {
        dfs(root,0);
        return m;
    }
};