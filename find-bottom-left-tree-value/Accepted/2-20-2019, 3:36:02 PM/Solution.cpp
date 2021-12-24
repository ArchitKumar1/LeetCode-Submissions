// https://leetcode.com/problems/find-bottom-left-tree-value

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
    vector<int> a[100000];
    int ma = 0;
    void dfs(TreeNode* root,int depth){
        if(root == NULL)
            return ;
        a[depth].push_back(root->val);
        ma = max(ma,depth);
        dfs(root->left,depth + 1);
        dfs(root->right,depth + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans;
        dfs(root,0);
        return a[ma][0];
    }
};