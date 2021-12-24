// https://leetcode.com/problems/add-one-row-to-tree

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
    int d1;
    int v1;
    void dfs(TreeNode* root,int depth){
        if(root == NULL)
            return ;
        if(depth == d1-1){
           
            TreeNode * left = root->left;
            TreeNode * right = root->right;

            root->left = new TreeNode(v1);
            root->right = new TreeNode(v1);
            root->left->left = left;
            root->right->right = right;
            return ;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth +1);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        d1 = d;
        v1 = v;
        if(d == 1){
            TreeNode* x =new TreeNode(v);
            x->left = root;
            return x;
        }
        dfs(root,1);
        return root;
    }
};