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
    ListNode* H;
    bool find(ListNode* head,TreeNode* root){
        bool ok = 0;
        if(head == NULL && root == NULL) {
            return 1;
        }
        if(head == NULL || root == NULL){
            return 0;
        }
        if(head->val != root->val){
            ok =  0;
        }else{
            ok = 1;
        }
        return ok || find(head->next,root->left) || find(head->next,root->right) || find(H,root->left) || find(H,root->right);
    
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        H = head;
        return find(H,root);
    }
};