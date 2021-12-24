// https://leetcode.com/problems/maximum-number-of-visible-points

class Solution {
public:
    double PI = acos(-1);
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        
        int px = location[0];
        int py = location[1];

        for(auto &x : points){
            x[0] -= px;
            x[1] -= py;
        }
        
        double top = PI/180 * angle;
        
        sort(points.begin(),points.end(),[&](vector<int> a,vector<int>b){
            double da = atan(1.0*a[1]/a[0]);
            double db = atan(1.0*b[1]/b[0]);
            return da < db;
        });
        int n = points.size();
        
        auto getangle = [&](int i) -> double{
            return atan(1.0*points[i][1]/points[i][0]);
        };
        int fans = 0;
        int ans = 0;
        
        for(int i = 0,j = 0;i<n;i++){
            ans += 1;
            while(getangle(i) > top){
                //update top to new top
                double base = getangle(j+1);
                top = base + PI/180 * angle;
                j++;
                ans -=1;
            }
            fans = max(fans,ans);
        }
        return fans;
        
    }

};