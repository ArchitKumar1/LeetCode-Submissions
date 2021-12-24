// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    
    
    int minCost(string s, vector<int>& cost) {
        
        int n =cost.size();
        
        int costi = cost[0];
        int maxi = cost[0];
        int ans= 0 ;
        
        for(int i =1;i<n;i++ ){
            if(s[i] == s[i-1]){
                costi += cost[i];
                maxi =max(maxi,cost[i]);
            }else{
                ans += costi - maxi;
                costi = cost[i];
                maxi = cost[i];
            }
        }
        ans += costi - maxi;
        return ans;
        
    }
};