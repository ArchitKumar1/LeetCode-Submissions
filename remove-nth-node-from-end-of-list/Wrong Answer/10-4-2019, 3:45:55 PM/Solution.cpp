// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* s = head;
        ListNode* p = head;
        int len = 0;
        while(p!=NULL){
            len++;
            p = p->next;
        }
        int pos = len -n+1;
        int scnt = 0;
        
        cout <<pos << endl;
        ListNode* dummy = new ListNode(3);
        ListNode* ans = dummy;
        while(s!=NULL){
            scnt++;
            if( scnt!=pos){
                dummy->next = s;
                dummy = dummy->next;
            }    
            s = s->next;
        }
        return ans->next;
    }
};