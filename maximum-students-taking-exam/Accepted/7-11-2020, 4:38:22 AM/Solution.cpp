// https://leetcode.com/problems/maximum-students-taking-exam

class Solution {
public:
    
    
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size();
        int m = seats[0].size();
        
        int ans = 0;
        
        vector<int> valid(n);
        for(int i = 0;i<n;i++){
            int val= 0 ;
            for(int j = 0;j<m;j++){
                val = val*2  + (seats[i][j] == '.');
            }
            valid[i] = val;
        }
        
        vector<vector<int>> dp(n+1,vector<int>(1<<m,-1));
        dp[0][0] = 0;
        
        for(int i =1;i<=n;i++){
            for(int j = 0; j < (1 << m); j++){
                if((j & valid[i-1]) == j && !(j & (j >> 1))){
                    for(int k = 0;k < (1 << m);k++){
                        if( !((k >> 1) & j) && !((j >> 1) & k) && dp[i - 1][k] != -1 ){
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + __builtin_popcount(j));
                        }
                    }
                }    
            }
        }
        return *max_element(dp[n].begin(),dp[n].end());

    }
};