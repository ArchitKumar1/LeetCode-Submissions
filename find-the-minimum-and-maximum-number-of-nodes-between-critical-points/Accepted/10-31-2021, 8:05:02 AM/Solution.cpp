// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nodes;
        
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }
        vector<int> pos;
        for(int i = 1;i+1 < nodes.size();i++){
            if(nodes[i-1] < nodes[i] && nodes[i] >  nodes[i+1]) pos.push_back(i);
            if(nodes[i-1] > nodes[i] && nodes[i] <  nodes[i+1]) pos.push_back(i);
        }
        vector<int> ans = {-1,-1};
        if(pos.size() < 2) return ans;
        
        int maxi = pos.back() - pos[0];
        int mini = INT_MAX;
        for(int i = 0;i + 1 < pos.size();i++){
            mini = min(mini,pos[i+1] - pos[i]);
        }
        ans[0] = mini;
        ans[1] = maxi;
        return ans;
    }
};