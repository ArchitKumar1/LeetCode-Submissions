// https://leetcode.com/problems/average-waiting-time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        double curr = customers[0][0];
        double ans = 0.0;
        for(int i = 0;i<n;i++){
            
            double st = 1.0*customers[i][0];
            double en = max(st,curr) + customers[i][1];
            
            ans += (en-st);
            curr = en;
            
        }
        return ans/n;
    }
};