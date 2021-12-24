// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> output;
        vector<pair<double,vector<int>>> point_dist;
        for(int i = 0; i < points.size(); i++)
        {
            double dist = sqrtf(powf(points[i][0],2) + powf(points[i][1],2));
            point_dist.push_back(make_pair(dist,points[i]));
        }
        sort(point_dist.begin(), point_dist.end());
        for(int k = 0; k < K; k++)
        {
            output.push_back(point_dist[k].second);
        }
        return output;
    }
};