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
                while(dq.size() > 2){
                    pair<int,int> p1 = dq.at(0);
                    pair<int,int> p2 = dq.at(1);
                    if(p1.first < p2.first) dq.pop_front();
                }
                while(dq.size() && x - dq.front().second > k) dq.pop_front();
                
                if(dq.size()) ans = max(ans,y+x + dq.front().first);
            }
            dq.push_back({y-x,x});
        }
        return ans; 
    }
};