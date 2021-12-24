// https://leetcode.com/problems/merge-in-between-linked-lists

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *st1,*en1;
        ListNode *ans = list1;
        while(list1){
            if(list1->next){
                if(list1->next->val == a){
                    st1 = list1;
                }
                if(list1->val == b){
                    en1 = list1->next;
                }
            }
            list1 = list1->next;
        }
        ListNode *st2= list2,*en2;

        while(list2){
            en2 = list2;
            list2 = list2->next;
            
        }
        st1->next = st2;
        en2->next = en1;
        
        return ans;
    }
};