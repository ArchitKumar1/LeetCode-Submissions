// https://leetcode.com/problems/profitable-schemes

class Solution {
public:
    
    int mod = pow(10,9) + 7;
    int n;
    int dp[120][120][120];
    
    int solve(int g ,int p,int curr,vector<int>&group,vector<int>&profit,int G,int P){
        cout << g << " " << p <<  " " << curr << endl;
        if(curr == n){
            if(g <=G && p>=P){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[g][p][curr]!=-1) return dp[g][p][curr];
        int total = (solve(g,p,curr+1,group,profit,G,P) +
                  solve(g+group[curr],p + profit[curr],curr+1,group,profit,G,P))%mod;
        
        return  dp[g][p][curr] = total;
    }
    
    
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        n = group.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,group,profit,G,P);
        
        
        
        
    }
};