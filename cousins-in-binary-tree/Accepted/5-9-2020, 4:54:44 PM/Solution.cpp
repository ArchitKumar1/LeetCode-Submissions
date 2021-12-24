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
    int da = 0,db = 0;
    
    void dfs(TreeNode* r,TreeNode* par ,int x,int y,int depth){
        if(!r) return ;
        if(r->val == x){
            a = par;
            da = depth;
        }
        if(r->val == y){
            b = par;
            db = depth;
        }
        dfs(r->left,r,x,y,depth+1);
        dfs(r->right,r,x,y,depth+1);
    }
    bool isCousins(TreeNode* root, int p, int q) {
        dfs(root,NULL,p,q,0);
        return a !=b && da == db;
    }
};