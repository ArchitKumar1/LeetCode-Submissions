// https://leetcode.com/problems/number-of-paths-with-max-score

class Solution {
    int dp[200][200];
    int maxi[200][200];
    int mod = 1e9+7;
public:
    int n ,m;
    vector<string> bo ;
    
    int solve(int i ,int j){
        if(i >=n || j>=m) return 0;
        
        if(dp[i][j]!= 0){
            return dp[i][j];
        }
        if(bo[i][j] == 'X') return 0;
        
        
        int ans = 0;
        
        int a = solve(i+1,j);
        int b = solve(i,j+1);
        int c = solve(i+1,j+1);
        int ret = max({a,b,c});
        
        
        int x = ret;
        if(x == a){
            (maxi[i][j] += maxi[i+1][j])%=mod;
        }
        if(x == b){
            (maxi[i][j] += maxi[i][j+1])%=mod;
        }
        if(x == c){
            (maxi[i][j] +=maxi[i+1][j+1])%=mod;
        }
        
        if(bo[i][j] != 'E' && bo[i][j]!='S') ret += bo[i][j] -'0';
        
        return dp[i][j] = ret;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        ios_base::sync_with_stdio(false);
        
        n = board.size();
        m = board[0].size();
        bo = board;
        maxi[n-1][m-1] = 1;
        
        memset(dp,0,sizeof(dp));
        int ans1 = solve(0,0);
        int ans2 = maxi[0][0];
        
        if(ans2 == 0){
            return vector<int>({0,0});
        }else
            return vector<int>({ans1,ans2});
    }
};