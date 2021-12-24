// https://leetcode.com/problems/cousins-in-binary-tree

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
    
    TreeNode* a,*b;
    
    
    void dfs(TreeNode* r,TreeNode* par ,int x,int y){
        if(!r) return ;
        if(r->val == x){
            a = par;
        }
        if(r->val == y){
            b = par;
        }
        dfs(r->left,r,x,y);
        dfs(r->right,r,x,y);
    }
    bool isCousins(TreeNode* root, int p, int q) {
        dfs(root,NULL,p,q);
        return a ==b;
    }
};