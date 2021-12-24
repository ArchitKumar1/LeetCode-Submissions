// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int x = points[0][0],y=points[0][1];
        
        for(int i = 1;i<points.size();i++){
            int xd =  abs(points[i][0]-x) ;
            int yd = abs(y-points[i][1]);
            ans += abs(xd-yd) + min(xd,yd);
            x = points[i][0];
            y = points[i][1];
            
        }
        return ans;
    }
};