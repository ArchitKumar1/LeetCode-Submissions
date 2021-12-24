// https://leetcode.com/problems/cousins-in-binary-tree

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
    int dx = 0;
    int dy = 0;
    int parx = 0;
    int pary = 0;
    int X;
    int Y;
    void dfs(TreeNode* root,int depth = 0,int par = -1 ){
        if(!root) return;
        if(root->val == X){
            parx = par;
            dx = depth;
        }
        if(root->val == Y){
            pary = par;
            dy = depth;
        }
        dfs(root->left,depth+1,root->val);
        dfs(root->right,depth+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        X = x;
        Y=y;
        dfs(root,0,-1);
        if(dx == dy && parx!=pary)
            return true;
        else
            return false;
    }
};