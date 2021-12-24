// https://leetcode.com/problems/subtree-of-another-tree

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(issametree(s,t)) return true;
        return isSubtree(s->right,t) || isSubtree(s->left,t);
    }
    bool issametree(TreeNode *s, TreeNode *t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val  != t->val) false;
        return issametree(s->right,t->left) && issametree(s->right,t->right);
    }
};