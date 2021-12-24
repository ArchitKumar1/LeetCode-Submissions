// https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        int p = 0;
        bool cycle = 0;
        
        while(slow && fast){
            if(p) slow = slow->next;
            fast = fast->next;
            p^=1;
            if(fast == slow){
                cycle =true;
                break;
            }
        }
        if(!cycle)return NULL;
        ListNode * f = slow;
        ListNode * s = head;
        
        cout << f->val << " " << s->val << endl;
        while(f != s){
            if(f->next)f = f = f->next->next;
            s = s->next;
               
        }
        return f;
    }
};