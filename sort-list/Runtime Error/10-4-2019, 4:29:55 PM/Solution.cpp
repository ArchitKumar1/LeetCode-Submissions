// https://leetcode.com/problems/sort-list

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
    ListNode* sortList(ListNode* head) {
        vector<ListNode*>all;
        ListNode* dummy =new ListNode(-(int)1e9);
        ListNode* ans =dummy;
        while(head){
            all.push_back(head);
            head = head->next;
        }
        
        sort(all.begin(),all.end(),[](ListNode* a,ListNode* b){return a->val <= b->val;});
        for(auto x : all){
            cout << x->val <<endl;
        }
        for(auto node : all){
            dummy->next = new ListNode(node->val);
            dummy = dummy->next;
        }
        return ans->next;
    }
};