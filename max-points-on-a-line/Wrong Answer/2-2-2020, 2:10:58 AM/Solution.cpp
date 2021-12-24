// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    pair<double,pair<int,int>> getslope(int a,int b,int c,int d){
        int x = c-a;
        int y = d-b;
        int ax = abs(x);
        int ay = abs(y);
        int GCD = __gcd(ax,ay);
        int xx = x/ GCD;
        int yy = y /GCD;
        
        if(xx !=0){
            return {a,{yy,xx}};
        }else{
            double c= 1.0*y - 1.0*x * yy/xx; 
            return {c,{yy,xx}};
        }
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<pair<double,pair<int,int>>,set<pair<int,int>>> m1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                m1[getslope(x1,y1,x2,y2)].insert({x1,y1});
                m1[getslope(x1,y1,x2,y2)].insert({x2,y2});
            }
        }
        int size= 0;
        for(auto x : m1){
            size = max(size,(int)x.second.size());
        }
        return size;
        
    }
};