// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int c : stones){
            pq.push(c);
        }
        if(stones.size() == 0) return 0;
        if(stones.size() == 1) return stones[0];
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            int c = abs(a-b);
            if(c!=0){
                pq.push(c);
            }
        }
        return (pq.size() == 0 ? 0 : pq.top());
    }
};