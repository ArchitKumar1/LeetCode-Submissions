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
        if(head == NULL || root == NULL){
            return 0;
        }
        if(head->next == NULL && root->val==head->val) {
            return 1;
        }
        if(root->val!= head->val){
            return find(H,root->left) || find(H,root->right);
        }else{
            return find(head->next,root->left) || find(head->next,root->right);
        }
    
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        H = head;
        return find(H,root);
    }
};