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

        if(points.size() == 0) return 0;
        int n = points.size();
        map<pair<double,pair<int,int>>,set<pair<int,int>>> m1;
        map<pair<int,int>,int> m2;
        for(int i =0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            m2[{x1,y1}] +=1;
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 == x2 && y1 == y2) continue;
                m1[getslope(x1,y1,x2,y2)].insert({x1,y1});
                m1[getslope(x1,y1,x2,y2)].insert({x2,y2});
            }
        }
        int size= 1;
        for(auto x : m1){
            auto ss = x.second;
            int cnt = 0;
            cout << x.first.first << " " << x.first.second.first << " " << x.first.second.second <<endl;
            for(auto it = ss.begin();it!=ss.end();it++){
                cout << (*it).first << " "<< (*it).second << endl;
                cnt += (m2[*it]);
            }
            size = max(size,cnt);
        }
        for(auto x : points){
            size= max(size,(int)m2[{x[0],x[1]}]);
        }
        return size;
        
    }
};