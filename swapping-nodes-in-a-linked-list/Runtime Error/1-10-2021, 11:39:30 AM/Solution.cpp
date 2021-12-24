// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> all;
        while(head){
            all.push_back(head);
            head = head->next;
        }
        int x = k-1;
        int y = all.size()-k;
        
        swap(all[x],all[y]);
        
        ListNode* H = new ListNode(0);
        ListNode* ANS = H;
        
        for(auto x : all){
            H->next = x;
            H = H->next;
        }
        return ANS->next;
    }
};