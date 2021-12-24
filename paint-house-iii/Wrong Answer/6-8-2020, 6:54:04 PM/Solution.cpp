// https://leetcode.com/problems/paint-house-iii

class Solution {
public:
    vector<int> H;
    vector<vector<int>> C;
    int M,N;
    int T;
    int inf = 1e9;
    
    int dp[100][25][100];
    
    int solve(int i,int j,int k){
        
        int ans = 0;
        if(H[i] != 0 ){
            if(j == H[i]) ans = 0;
            return inf;
        }else{
            ans = C[i][j-1];
        }
        
        int next = inf;
        
        if(i+1<M){
            for(int c =1;c<=N;c++){
                if(c == j) next = min(next,solve(i+1,c,k));
                else next = min(next,solve(i+1,c,k+1));
            }
            return ans + next;
        }else{
            if(k == T) return ans;
            else return inf;
        }

    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        H = houses;
        C = cost;
        M = m;
        N = n;
        T = target;
        
        memset(dp,0,sizeof(dp));
        int ans =inf;
        for(int i = 1;i<=n;i++){
            ans = min(ans,solve(0,i,1));
        }
        return ans>= 1e9 ? -1 : ans;
    }
};