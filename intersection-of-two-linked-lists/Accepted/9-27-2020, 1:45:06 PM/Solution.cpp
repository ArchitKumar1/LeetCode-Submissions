// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        
        int x=0,y=0;
        while(a){
            x++;
            a = a->next;
        }
        while(b){
            y++;
            b = b->next;
        }
        //cout << x << " " << y << endl;
        int diff  = x-y;
        a = headA,b = headB;
        if(diff > 0){
            while(diff--){
                a = a->next;
            }
        }else if(diff < 0){
            diff*=-1;
             while(diff--){
                b = b->next;
            }
        }
        while(a && b && a!=b){
            a = a->next;
            b = b->next;
        }
        return a;
    }
};