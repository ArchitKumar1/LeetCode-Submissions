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
        if(sameTree(s,t)) return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    // bool issametree(TreeNode *s, TreeNode *t){
    //     if(!s && !t) return true;
    //     if(!s || !t) return false;
    //     if(s->val  != t->val) false;
    //     return issametree(s->left,t->left) && issametree(s->right,t->right);
    // }
    // bool isSubtree(TreeNode* s, TreeNode* t) {
    //     if (!s) return false;
    //     if (sameTree(s, t)) return true;
    //     return isSubtree(s->left, t) || isSubtree(s->right, t);
    // }
    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
};