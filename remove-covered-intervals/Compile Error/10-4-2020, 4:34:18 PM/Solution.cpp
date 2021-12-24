// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        
        sort(in.begin(),in.end());
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
        return n- ans;
    }
};