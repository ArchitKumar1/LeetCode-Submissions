// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        auto inside = [&](vector<int> c,vector<int>p){
            
        };
        
        vector<int> res(queries.size());
        int pos = 0;        
        for(auto c : queries){
            for(auto p : points){
                int dx = c[0]-p[0];
                int dy = c[1]-p[1];
                int r = c[2];
                if ((dx*dx+dy*dy) <= r*r){
                    res[pos]++;   
                }
            }
            pos++;
        }
        return res;
    }
};