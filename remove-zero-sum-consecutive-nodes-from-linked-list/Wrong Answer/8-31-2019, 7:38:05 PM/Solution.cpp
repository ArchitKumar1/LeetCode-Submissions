// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<ListNode*> all;
        vector<int> pos;
        ListNode* d = head;
        while(d){
            all.push_back(d);
            d = d->next;
        
        }
        int n = all.size();
        pos.assign(n,1);
        int sum = 0;
        int st = 0;
        for(int i=0;i<n;i++){
            ListNode* t = all[i];
            sum+= t->val;
            if(sum == 0 && i!=0){
                for(int j=st;j<=i;j++){
                    pos[j] = 0;
                }
                st = i+1;
                sum = 0;
            }
        }
        ListNode* dummy = new ListNode(1);
        ListNode* start = dummy;
        for(int i=0;i<n;i++){
            if(pos[i]){
                dummy->next = new ListNode(all[i]->val);
                dummy = dummy->next;
            }
        }
        for(int i=0;i<n;i++){
            cout << pos[i] << " ";
        }
        return start->next;
        
    }
};