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
        
        cout << i << " " << j << " " << k << endl;
        int ans = inf;
        
        if(i == M){
            if(k ==T) return 0;
            else return inf;
        }
        if(H[i] != 0 && H[i] !=j) return inf;
        
        for(int x= 0;x<N;x++){
            if(H[i] == 0){
                if(x == j) ans = min(ans,C[i][j] + solve(i+1,x,k));
                else ans = min(ans,C[i][j] + solve(i+1,x,k+1));
            }else{
                if(x == j) ans = min(ans,solve(i+1,x,k));
                else ans = min(ans,solve(i+1,x,k+1));
            }
        }   
        
        
        return ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        H = houses;
        C = cost;
        M = m;
        N = n;
        T = target;
        
        memset(dp,0,sizeof(dp));
        int ans =inf;
        for(int i = 0;i<n;i++){
            ans = min(ans,solve(0,i,1));
        }
        return ans;
    }
};