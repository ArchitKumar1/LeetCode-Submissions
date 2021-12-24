// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        vector<int> back = points[0];
        for(auto x : points){
            int dx = abs(x[0]-back[0]);
            int dy = abs(x[1]-back[1]);
            ans += max(dx,dy);
            back = x;
        }
        return ans;
    }
};