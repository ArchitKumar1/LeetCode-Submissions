// https://leetcode.com/problems/max-value-of-equation

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        
        priority_queue<pair<int,int>> pq;
        int n = p.size();
        int ans = 0
        for(int i =1;i<n;i++){
            auto x = p[i][0],y = p[i][1];
            if(i > 0){
                while(pq.size() && x - pq.top().second > k) pq.pop();
                if(pq.size()) ans = max(ans,y+x + pq.top().first);
            }
            pq.push({y-x,x});
        }
        return ans; 
    }
};