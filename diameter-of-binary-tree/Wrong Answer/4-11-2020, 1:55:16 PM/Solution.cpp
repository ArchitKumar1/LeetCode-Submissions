// https://leetcode.com/problems/diameter-of-binary-tree

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
    int l = 0;
    int r = 0;
    
    void dfs(TreeNode* root,int d){
        if(root == NULL) return;
        l = min(l,d);
        r = max(r,d);
        dfs(root->right,d+1);
        dfs(root->left,d-1);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root,0);
        cout << r << " " << l << endl;
        return r-l;
    }
};