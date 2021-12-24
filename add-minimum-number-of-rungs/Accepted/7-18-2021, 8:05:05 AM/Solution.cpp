// https://leetcode.com/problems/add-minimum-number-of-rungs

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        rungs.insert(rungs.begin(),0);
        int ans = 0 ;
        int n = rungs.size();
        for(int i = 1;i < n;i++){
            int g = rungs[i] - rungs[i-1];
            if( g <= dist){
                continue;
            }else{
                int cnt =(g / dist)- (g%dist == 0);
                ans += cnt;
            }
        }
        return ans;
    }
};