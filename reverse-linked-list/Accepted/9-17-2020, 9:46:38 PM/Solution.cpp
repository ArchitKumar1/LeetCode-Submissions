// https://leetcode.com/problems/reverse-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // a - > b -> c 
        //      curr next
            
        ListNode* root = head;
        
        if(!root || root->next == NULL) return head;
        
        ListNode* curr = head;
        ListNode* back = NULL;
        ListNode* next = head;
        
        while(curr && next){
           
            next = next->next;
            curr->next = back;
            back = curr;
            curr = next;
        }
        return back;
    }
};