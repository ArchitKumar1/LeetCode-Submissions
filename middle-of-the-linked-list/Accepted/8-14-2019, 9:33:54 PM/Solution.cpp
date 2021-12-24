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
        int cnt = 0;
        ListNode* ans,*head2 = head;
        
        while(head!= NULL){
            cnt++;
            head = head->next;
        }
        int pos = 0;
        while(head2!= NULL){
            
            if(pos == cnt/2){
                ans = head2;
            }
            pos++;
            head2= head2->next;
        }
        return ans;
    }
};