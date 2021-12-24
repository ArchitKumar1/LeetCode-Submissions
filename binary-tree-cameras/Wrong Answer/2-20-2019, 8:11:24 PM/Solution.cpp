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
    int cam1 = 0;
    int cam2 = 0;
    int odd = 0,even = 0;
    void dfs(TreeNode* root,int depth){
        if(root == NULL) return;
        (depth % 2 == 0) ? even++ : odd++;
        dfs(root->right,depth + 1);
        dfs(root->left,depth + 1);
    }
    // void dfs1(TreeNode* root,int state){
    //     if(root == NULL) return;
    //     if(state == 0){
    //         cam1++;
    //         state=1;
    //     }
    //     else{
    //         state=0;
    //     }
    //     dfs1(root->right,state);
    //     dfs1(root->left,state);
    // }
    // void dfs2(TreeNode* root,int state){
    //     if(root == NULL) return;
    //     if(state == 0){
    //         cam2++;
    //         state=1;
    //     }
    //     else{
    //         state=0;
    //     }
    //     dfs2(root->right,state);
    //     dfs2(root->left,state);
    // }
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1+max(depth(root->right),depth(root->left));
    }
    int minCameraCover(TreeNode* root) {
        if(depth(root) == 1) return 1;
        dfs(root,0);
        return min(odd,even);
    }
};