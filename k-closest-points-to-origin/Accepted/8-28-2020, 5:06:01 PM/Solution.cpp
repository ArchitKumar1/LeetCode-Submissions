// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[](vector<int> a,vector<int>b){
            double x  = a[0]*a[0]+a[1]*a[1];
            double y  = b[0]*b[0]+b[1]*b[1];
            return x < y;
        });
        points.resize(K);
        return points;
    }
};