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
        ListNode * fast = head->next;
        bool cycle = 0;
        
        while(slow && fast){
            if(fast == slow){
                cycle =true;
                break;
            }
            slow = slow->next;
            if(fast->next) fast = fast->next->next;
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