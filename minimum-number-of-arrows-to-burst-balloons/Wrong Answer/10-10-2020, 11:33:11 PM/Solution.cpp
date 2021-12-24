// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        long long int b = -1e18;
        
        sort(points.begin(),points.end(),[&](vector<int> a,vector<int>b){
            return a[0] < b[0];
        });
        int ans = 0;
        for(auto x : points){
            if(x[0] > b){
                ans += 1;
                b = max(b,(long long)x[1]);
            }else{
                b = max(b,(long long)x[0]);
            }
            
        }
        return ans;
    }
};