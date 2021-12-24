// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    
    void make(TreeNode* root,vector<int> p){
        if(p.size() == 0) return ;        
        vector<int> x,y;
        for(int c : p){
            if(c < root->val){
                x.push_back(c);
            }else{
                y.push_back(c);
            }
        }
        if(x.size()){
            root->left = new TreeNode(x[0]);
            x.erase(x.begin());
            make(root->left,x);
        }
        if(y.size()){
            root->right = new TreeNode(y[0]);
            y.erase(y.begin());
            make(root->right,y);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        TreeNode* root = new TreeNode(p[0]);
        p.erase(p.begin());
        make(root,p);
        return root;
    }
    
};