// https://leetcode.com/problems/max-points-on-a-line

class Solution {
    #define LL long long int
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<array<LL,2>> V(n);
        
        for(int i = 0;i<n;i++){
            V[i][0] = points[i][0];
            V[i][1] = points[i][1];
        }
        
        LL ans = V.size()>=1 ;
        
        for(int i = 0;i<n;i++){
            auto[x1,y1] = V[i];
            map<vector<LL>,int> m1;
            int cnt = 1;
            
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                auto[x2,y2] = V[j];
                
                if(x1 == x2 && y1 == y2){
                    cnt += 1;
                    continue;
                }
                LL a = y1-y2;
                LL b = x2-x1;
                LL c = (x1-x2)*y1 + (y2-y1)*x1;
                
                LL gcd = __gcd(a,__gcd(b,c));
                if(gcd==0)gcd=1;
                a = a/gcd,b=b/gcd,c=c/gcd;
                
                m1[vector<LL>({a,b,c})]++;
            }
            ans = max(ans,cnt);
            
            for(auto x : m1){
                if(x.second >=1)
                    ans = max(ans,cnt + x.second);
            }
        }
        return ans;
    }
};