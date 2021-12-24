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
        ListNode *st = new ListNode(1);
        ListNode *ans = st;
        set<pair<int,ListNode*>> ss;
        
        while(head){
            ss.insert({head->val,head});
            head = head->next;
        }
        while(ss.size()){
            pair<int,ListNode*> temp = *ss.begin();
            ss.erase(ss.begin());
            st->next = temp.second;
            st = st->next;
        }
        return ans->next;
    }
};