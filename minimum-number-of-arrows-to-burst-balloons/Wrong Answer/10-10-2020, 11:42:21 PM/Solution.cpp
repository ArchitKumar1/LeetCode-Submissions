// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(),points.end(),[&](vector<int> a,vector<int>b){
            return a[0] < b[0];
        });
        int ans = 1;
        vector<int> b = points[0];
        for(int i = 1;i<points.size();i++){
            auto v = points[i];
            if(v[0] <= b[1]){
                b[0] = v[0];
            }else{
                b = v;
                ans += 1;
            }
        }
        return ans;
    }
};