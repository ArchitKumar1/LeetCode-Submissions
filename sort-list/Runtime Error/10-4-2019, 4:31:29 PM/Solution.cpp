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
        vector<int>all;
        ListNode* dummy =new ListNode(-(int)1e9);
        ListNode* ans =dummy;
        while(head){
            all.push_back(head->val);
            head = head->next;
        }
        
        sort(all.begin(),all.end(),[](int a,int b){return a<=b;});
        for(auto x : all){
            cout << x << endl;
        }
        for(auto node : all){
            dummy->next = new ListNode(node);
            dummy = dummy->next;
        }
        return ans->next;
    }
};