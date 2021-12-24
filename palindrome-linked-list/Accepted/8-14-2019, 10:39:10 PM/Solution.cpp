// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> all;
        while(head){
            all.push_back(head);
            head =head->next;
        }
        int n = all.size();
        int i =0 ;
        int j = n-1;
        while(i<=j){
            if(all[i]->val!= all[j]->val){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
};