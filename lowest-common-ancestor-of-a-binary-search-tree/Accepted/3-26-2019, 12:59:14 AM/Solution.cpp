// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        while(1){
            if(p->val  < root->val && q->val < root->val ){
                root = root->left;
                continue;
            }
            if(p->val  > root->val && q->val > root->val ){
                root = root->right;
                continue;
            }
            break;
        }
        return root;
    }
};