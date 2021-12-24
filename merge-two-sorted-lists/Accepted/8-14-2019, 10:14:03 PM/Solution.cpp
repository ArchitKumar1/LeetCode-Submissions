// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *fake = new ListNode(22);
        ListNode *h1 = l1,*h2 = l2;
        ListNode *ans = fake;
        while(h1!= NULL || h2!= NULL){
            if(h2 == NULL){
                fake->next = h1;
                h1 =h1->next;
                fake = fake->next;
            }else if(h1 == NULL){
                fake->next = h2;
                h2 =h2->next;
                fake = fake->next;
            }
            else if(h1->val > h2->val){
                fake->next = h2;
                h2 =h2->next;
                fake = fake->next;
            }else{
                fake->next = h1;
                h1 =h1->next;
                fake = fake->next;
            }
        }
        return ans->next;
    }
};