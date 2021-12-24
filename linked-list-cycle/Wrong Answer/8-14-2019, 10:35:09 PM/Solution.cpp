// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> m1;
        map<ListNode*,int> m2;
        int pos = 1 ;
        m2[head] = 1;
        m1[head] = 1;
        if(!head || !head->next) return 0;
        while(head){
            if(m1[head]) return 1;
            m1[head] = 1;
            m2[head] = ++pos;
            head = head->next;
        }
        return 0;
    }
};