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
        pos.assign(n,0);
        int sum = 0;
        int st = 0;
        for(int i=0;i<n;i++){
            ListNode* t = all[i];
            sum+= t->val;
            if(sum == 0 && i!=0){
                for(int j=st;j<=i;j++){
                    pos[j] = 0;
                }
                st = i;
                sum = 0;
            }
        }
        ListNode* dummy;
        for(int i=0;i<n;i++){
            if(pos[i]){
                dummy->next = all[i];
                dummy = dummy->next;
            }
        }
        //return dummy->next;
        for(int i=0;i<n;i++){
        cout << pos[i] << " ";
        }
        
    }
};