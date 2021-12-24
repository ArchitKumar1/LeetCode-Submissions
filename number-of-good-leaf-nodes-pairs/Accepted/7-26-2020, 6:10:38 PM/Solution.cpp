// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs

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
    int fans =0 ;
    int D;
    void dfs(TreeNode* root){
        if(!root) return ;
        vector<int>x,y;
        solve(root->left,x,1),solve(root->right,y,1);
        
        for(int c : x){
            for(int d : y){
                if( c + d <= D){
                    fans += 1;
                }
            }
        }
        dfs(root->left),dfs(root->right);
    }
    
    void solve(TreeNode* root,vector<int> &leafs,int dist){
        if(!root) return;
        if(!root->left && !root->right){
            leafs.push_back(dist);
        }else {
            solve(root->left,leafs,dist+1);
            solve(root->right,leafs,dist+1);
        }
    }
    
    int countPairs(TreeNode* root, int distance) {
        D = distance;
        dfs(root);
        return fans;
    }
};