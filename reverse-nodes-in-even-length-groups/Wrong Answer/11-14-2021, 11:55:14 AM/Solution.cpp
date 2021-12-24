// https://leetcode.com/problems/reverse-nodes-in-even-length-groups

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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> nodes;
        ListNode* h = head;
        while(h){
            nodes.push_back(h->val);
            h = h->next;
        }
        int n = nodes.size();
        for(int i = 0,j = 0,cnt= 1,p = 0;i < n && j < n; ){
            j = i + cnt - 1;
            if(j > n-1) j = n-1;
            if(p) reverse(nodes.begin() + i,nodes.begin() + j + 1);
            i = j + 1;
            cnt += 1;
            p ^= 1;
        }
        ListNode *ans = new ListNode(nodes[0]);
        ListNode *fans = ans;
        
        for(int i = 1;i < n;i++){
            ListNode *newnode = new ListNode(nodes[i]);
            ans->next = newnode;
            ans = newnode;
        }
        return fans;
    }
};