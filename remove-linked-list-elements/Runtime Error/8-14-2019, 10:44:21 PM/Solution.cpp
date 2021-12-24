// https://leetcode.com/problems/remove-linked-list-elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ans,*trav;
        trav = head,ans = head;
        trav = head->next;
        if(!head) return head;
        while(head || trav){
            if(trav== NULL){
                head->next = NULL;
                break;
            }
            else if(trav->val == val){
                trav = trav->next;
            }else{
                head->next = trav;
                head = head->next;
                trav = trav->next;
            }
        }
        return ans;
    }
};