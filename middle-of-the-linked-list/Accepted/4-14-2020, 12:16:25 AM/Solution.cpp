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
        int p = 0;
        ListNode *h = head ,*i = head;
        while(h){
            h = h->next;
            if(p) i= i->next;
            p^=1;
        }
        return i;
    }
};