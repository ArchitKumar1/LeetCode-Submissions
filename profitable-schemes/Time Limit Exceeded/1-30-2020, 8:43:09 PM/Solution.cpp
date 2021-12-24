// https://leetcode.com/problems/profitable-schemes

class Solution {
public:
    
    int mod = pow(10,9) + 7;
    int n;
    map<pair<int,pair<int,int>>,int> m1;
    
    int solve(int g ,int p,int curr,vector<int>&group,vector<int>&profit,int G,int P){
        
        if(curr == n){
            if(g <=G && p>=P){
                return 1;
            }else{
                return 0;
            }
        }
        if(m1[{g,{p,curr}}]!=0) return m1[{g,{p,curr}}];
        int total = (solve(g,p,curr+1,group,profit,G,P) +
                  solve(g+group[curr],p + profit[curr],curr+1,group,profit,G,P))%mod;
        
        return  m1[{g,{p,curr}}] = total;
    }
    
    
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        n = group.size();
        //memset(dp,-1,sizeof(dp));
        return solve(0,0,0,group,profit,G,P);
        
    }
};