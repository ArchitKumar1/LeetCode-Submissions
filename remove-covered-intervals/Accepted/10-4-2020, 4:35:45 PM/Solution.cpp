// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        
        sort(in.begin(),in.end(),[&](vector<int>x,vector<int>y){
            if(x[0]!=y[0]){
                return x[0] < y[0];
            }else{
                return y[1] < x[1];
            }
        });
        auto beg = in[0];
        
        int ans = 0;
        for(int i = 1;i<in.size();i++){
            auto v = in[i];
            if(v[1] <=  beg[1]) ans++;
            if(v[0] <= beg[1]){
                beg[1] = max(beg[1],v[1]);
            }else{
                beg = v;
            }
        }
        return (int)in.size()- ans;
    }
};