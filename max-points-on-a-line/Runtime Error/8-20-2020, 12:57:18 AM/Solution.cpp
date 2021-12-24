// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<array<int,2>> V(n);
        
        for(int i = 0;i<n;i++){
            V[i][0] = points[i][0];
            V[i][0] = points[i][1];
        }
        
        int ans =0 ;
       
        
        for(int i = 0;i<n;i++){
            auto[x1,y1] = V[i];
            map<vector<int>,int> m1;
            
            for(int j = i+1;j<n;j++){
                auto[x2,y2] = V[j];
                
                int a = y1-y2;
                int b = x2-x1;
                int c = (x1-x2)*y1 + (y2-y1)*x1;
                
                int gcd = __gcd(a,__gcd(b,c));
                cout << gcd << endl;
                a = a/gcd,b=b/gcd,c=c/gcd;
                m1[vector<int>({a,b,c})]++;
            }
            for(auto x : m1){
                ans = max(ans,x.second+1);
            }
        }
        return ans;
    }
};