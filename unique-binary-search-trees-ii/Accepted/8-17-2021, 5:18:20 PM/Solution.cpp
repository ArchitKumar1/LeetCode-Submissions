// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    vector<TreeNode*> solve(int l,int r ) {
        if( l > r) return {NULL};
        vector<TreeNode*>  ans,left,right;
        for(int i = l;i <=r;i++){
            left = solve(l,i-1);
            right = solve(i+1,r);
            for(auto L : left){
                for(auto R : right){
                    TreeNode *node = new TreeNode(i);
                    node->left = L;
                    node->right = R;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};