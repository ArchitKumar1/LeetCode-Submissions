// https://leetcode.com/problems/max-value-of-equation

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        
        deque<pair<int,int>> dq;
        int n = p.size();
        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            auto x = p[i][0],y = p[i][1];
            if(i > 0){
                while(dq.size() && x - dq.front().second > k) dq.pop_front();
                if(dq.size()) ans = max(ans,y+x + dq.front().first);
                
                while(dq.size() && dq.front().first < (y - x)){
                    dq.pop_front();
                }
            }
            dq.push_back({y-x,x});
        }
        return ans; 
    }
};