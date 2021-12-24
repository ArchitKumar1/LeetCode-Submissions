// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* st1,*st2;
        st1 = head;
        ListNode* ans = new ListNode(1);
        st2 = ans;
        vector<ListNode*> vv;
        int pos = 0;
        while(head){
            if(pos <k){
                pos++;
                vv.push_back(head);
                head = head->next;
            }else{
                pos = 0;
                reverse(vv.begin(),vv.end());
                for(auto x: vv){
                    ans->next = x;
                    ans = ans->next;
                }
                vv.clear();
            }        
        }
        if(vv.size());
        reverse(vv.begin(),vv.end());
        for(auto x: vv){
            ans->next = x;
            ans = ans->next;
        }
        vv.clear();
        return st2->next;
    }
};