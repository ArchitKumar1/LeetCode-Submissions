// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities

class Solution {
public:

    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {        
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        for(auto e : edges){
            int u = e[0]-1,v = e[1]-1;
            dp[u][v] = dp[v][u] = (u!=v ? 1 : 0);
        }
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+ dp[k][j]);
                }
            }
        }
        vector<int> fans(n,0);
        for(int k = 0;k<(1<<n);k++){
            int e = 0,no = 0,mx = 0;
            for(int i = 0;i<n;i++){
                if(k&(1<<i)) no++;
                for(int j = i+1;j<n;j++){
                    if(k&(1<<i) && k&(1<<j)){
                        if(dp[i][j] == 1){
                            e += 1;
                        }
                        mx = max(mx,dp[i][j]);
                    }
                }
            }
            if(e == no-1 && mx > 0){
                fans[mx]++;
            }
        }
        fans.erase(fans.begin());
        return fans;
    }
};