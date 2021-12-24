// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev,*next;
        prev = NULL;
        next = head;
        while(head!= NULL and next!= NULL){
            next = next->next;
            head->next = prev;
            prev = head;
            head = next;
            
            
        }
        return prev;
    }
};