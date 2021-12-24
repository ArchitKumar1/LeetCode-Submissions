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
        if(!head) return head;
        ListNode *ans,*trav;
        ans = head;
        trav = head->next;
        if(trav_next == NULL){
            if(trav->val == val)return NULL;
            else return head;
        }
        while(head){
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