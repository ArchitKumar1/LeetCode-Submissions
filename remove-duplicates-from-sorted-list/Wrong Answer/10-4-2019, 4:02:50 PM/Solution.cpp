// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = head;
        if(head == NULL) return head;
        ListNode *next = head->next;       
        
        while(head!=NULL && next!=NULL){
            if(next == NULL) break;
            if(next->val == head->val){
                next = next->next;
            }else{
                head->next = next;
                next = next->next;
                head = head->next;
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         while(head!= NULL || next != NULL){
//             if(next == NULL){
//                 head->next = next;
//                 head = head->next;
//             }
//             else if(next->val == head->val){
//                 next = next->next;
//             }else{
//                 head->next = next;
//                 head = head->next;
//                 next = next->next;
//             }
//         }
        return ans;
    }
};