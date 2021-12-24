// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        sort(c.begin(),c.end());
        set<double> s;
        int inf = 1e9;
        for(int i =0 ;i+1<c.size();i++){
            double x2 = c[i+1][0],y2 = c[i+1][1];
            double x1 = c[i+1][0],y1 = c[i+1][1];
            
            if(x1-x2){
                s.insert(inf);
            }else{
                s.insert(1.0*(y2-y1)/(x2-x1));
            }
        }
        return s.size();
    }
};