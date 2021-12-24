// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    int N,M,O;
    int dp[2000][2000] = {3};
    string S1,S2,S3;
    
    
    int solve(int x,int y){
        if(x == N && y == M){
            if(x +y == O) return  1;
            else return 0;
        }
        if(dp[x][y] !=3){
            return dp[x][y];
        }
        int ok = 0;
        if(y == M){
            if(S1[x] == S3[x+y]){
                ok |= solve(x+1,y);
            }
        }
        else if(x == N){
            if(S2[y] == S3[x+y]){
                ok |= solve(x,y+1);
            }
        }else{
            if(S1[x] == S3[x+y]){
                ok |= solve(x+1,y);
            }
            if(S2[y] == S3[x+y]){
                ok |= solve(x,y+1);
            }
        }
        
        return dp[x][y] = ok;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        N = s1.size();
        M = s2.size();
        O = s3.size();
        for(int i = 0;i<=N;i++){
            for(int j = 0;j<=M;j++){
                dp[i][j] = 3;
            }
        }
        S1 = s1,S2 = s2,S3 = s3;
        
        return (bool)solve(0,0);
    }
};