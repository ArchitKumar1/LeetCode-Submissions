// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int n=N,m=N;
        
        int nmines[n+2][m+2];
        memset(nmines,0,sizeof(nmines));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                nmines[i][j] = 1;
            }
        }
        for(auto c : mines){
            nmines[c[0] +1][c[1] + 1] = 0;
        }
        int dp[n+2][m+2][4];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                dp[i][j][0] = (nmines[i][j] ? dp[i][j-1][0] + 1 : 0);
                dp[i][m-j + 1][1] = (nmines[i][m-j + 1] ? dp[i][m-j + 1+1][1] + 1 : 0);
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j = m;j>=1;j--){
        //          dp[i][j][1] = (nmines[i][j] ? dp[i][j+1][1] + 1 : 0);
        //     }
        // }
        for(int j = 1;j<=m;j++){
            for(int i = n;i>=1;i--){
                dp[i][j][2] = (nmines[i][j] ? dp[i+1][j][2] + 1 : 0);
            }
        }
        for(int j = 1;j<=m;j++){
            for(int i = 1;i<=n;i++){
                dp[i][j][3] = (nmines[i][j] ? dp[i-1][j][3] + 1 : 0);
            }
        }
        int fans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nmines[i][j]){
                    int ans = min(min(dp[i][j][0],dp[i][j][1]),min(dp[i][j][2],dp[i][j][3]));
                    // for(int k= 0;k<4;k++){
                    //    cout << dp[i][j][k] << endl;
                    // }
                    // cout << endl;
                    fans = max(fans ,ans);
                }
            }
        }
        return fans;
    }
};