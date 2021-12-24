// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 
        for(int i=0;i<points.size();i++){
            double dist =  1.0 * sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({dist,{points[i][0],points[i][1]}});
        }
        vector<vector<int>> ans;
        for(int i=0;i<K;i++){
            vector<int> temp;
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            temp.push_back(p.second.first);
            temp.push_back(p.second.second);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};