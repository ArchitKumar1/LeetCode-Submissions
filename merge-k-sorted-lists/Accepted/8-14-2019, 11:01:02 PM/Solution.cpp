// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* st = new ListNode(1);
        ListNode *st2 =st;
        set<pair<int,ListNode*>> ss;
        for(ListNode* x : lists){
            while(x){
                ss.insert({x->val,x});
                x=x->next;
            }
        }
        while(ss.size()){
            pair<int,ListNode*> temp = *ss.begin();
            ss.erase(ss.begin());
            cout << temp.first << " ";
            st->next = temp.second;
            st = st->next;
        }
        return st2->next;
    }
};