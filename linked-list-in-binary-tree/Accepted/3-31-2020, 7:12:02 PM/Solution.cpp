// https://leetcode.com/problems/linked-list-in-binary-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool dfs(ListNode* head,TreeNode* root){
        if(!head) return 1;
        if(!root) return 0;
        return (head->val == root->val) && (dfs(head->next,root->right) || dfs(head->next,root->left));
    
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)return 1;
        if(!root)return 0;
        return dfs(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
    

};