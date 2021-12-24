// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[](vector<int> a,vector<int>b){
            double x  = pow(1.0*a[0],2) + pow(1.0*a[1],2);
            double y  = pow(1.0*b[0],2) + pow(1.0*b[1],2);
            return x < y;
        });
        points.resize(K);
        return points;
    }
};