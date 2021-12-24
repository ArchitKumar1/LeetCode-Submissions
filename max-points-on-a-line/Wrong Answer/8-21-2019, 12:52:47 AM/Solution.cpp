// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<double,set<pair<int,int>>> m1;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                double d;
                if(x2-x1 == 0){
                    d = 0;
                }else{
                    d = (1.0)*(y2-y1)/((1.0*(x2-x1))); 
                }
                m1[d].insert({x1,y1});
                m1[d].insert({x2,y2});
            }
        }
        int ans = 0;
        for(auto x : m1){
            set<pair<int,int >> ss = x.second;
            int temp =  ss.size();
            ans = max(temp,ans);
        }

        if(n == 1) return 1;
        else{
            return ans;
        }
    }
};