// https://leetcode.com/problems/grid-game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
                long long n = grid[0].size();

        vector<vector<long long>>G1(2,vector<long long>(n,0));
        vector<vector<long long>>G2(2,vector<long long>(n,0));
        
        for(int i = 0; i < 2;i++){
            for(int j = 0;j < n;j++){
                G1[i][j] = G2[i][j] = grid[i][j];
            }
        }
        for(int i = 1;i < n;i++){
            G1[0][i] += G1[0][i-1]; 
            G1[1][i] += G1[1][i-1];
        }
        for(int i = n-2;~i;i--){
            G2[0][i] += G2[0][i+1];
            G2[1][i] += G2[1][i+1];
        }
        long long ans = 1e18;
        
        for(int i = 2;i<n;i++){
            ans = min(max(G1[1][i-2] , G2[0][i]),ans);
        }
        ans = min(ans,G1[1][n-2]);
        ans = min(ans,G2[0][1]);
        return ans;
    }
};