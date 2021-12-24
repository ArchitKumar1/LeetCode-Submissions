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
        if(!head || !head->next) return NULL;
        ListNode * slow = head;
        ListNode * fast = head;
        bool cycle = 0;
        
        while(slow && fast){
            slow = slow->next;
            if(fast->next) fast = fast->next->next;
            if(fast == slow){
                cycle =true;
                break;
            }
        }
        if(!cycle)return NULL;
        ListNode * f = head;
        ListNode * s = slow;
        
        cout << f->val << " " << s->val << endl;
        while(f != s){
            f = f->next;
            s = s->next;
               
        }
        return f;
    }
};