// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        auto inside = [&](vector<int> c,vector<int>p){
            int dx = c[0]-p[0];
            int dy = c[1]-p[1];
            int r = c[2];
            return ((dx*dx+dy*dy) <= r*r);
        };
        
        vector<int> res(queries.size());
        int pos = 0;        
        for(auto q : queries){
            for(auto p : points){
                if(inside(q,p)){
                    res[pos]++;   
                }
            }
            pos++;
        }
        return res;
    }
};