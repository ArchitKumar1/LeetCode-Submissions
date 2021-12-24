// https://leetcode.com/problems/max-points-on-a-line

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float,int> slopes;
        int res = 0;
        for(int i=0;i<points.size();i++){
            slopes.clear();
            int duplicate = 1;
            for(int j=i+1;j<points.size();j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    duplicate++;
                float slope = 1.0;
                if(points[i].x == points[j].x)
                    slope = INT_MAX;
                else{
                    slope = (float) (points[j].y - points[i].y)/(points[j].x - points[i].x);
                }
                slopes[slope]++;
            }
            res = max(res, duplicate);
            for (auto slope : slopes)
                if (slope.second + duplicate > res) 
                    res = slope.second + duplicate; 
        }
        return res;
    }
};