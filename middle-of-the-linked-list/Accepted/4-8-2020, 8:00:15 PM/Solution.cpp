// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        ListNode* ans;
        ListNode* h1 = head,*h2 = head;
        h1 = h1->next;
        while(h1){
            
        h1 = h1->next;

            if(h1)h1= h1->next;
            h2 = h2->next;
        }
        return h2;
    }
};