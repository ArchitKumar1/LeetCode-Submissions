// https://leetcode.com/problems/path-sum-iii

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
    int fans = 0;
    
    int dfs1(TreeNode* root, int sum){
        if(!root)return 0;
        int val = root->val;
        int ans = (sum-val)==0;
        ans += dfs1(root->left,sum-val);
        ans += dfs1(root->right,sum-val);
        return ans;
    }
    
    void dfs(TreeNode* root, int sum){
        if(!root)return;
        int ans = 0;
        fans += dfs1(root,sum);
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return fans;
    }
};