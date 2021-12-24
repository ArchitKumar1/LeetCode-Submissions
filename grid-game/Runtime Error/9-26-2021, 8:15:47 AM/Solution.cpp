// https://leetcode.com/problems/grid-game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<vector<int>> G1 = grid;
        vector<vector<int>> G2 = grid;
        int n = grid[0].size();
        for(int i = 1;i < n;i++){
            G1[0][i] += G1[0][i-1]; 
            G1[1][i] += G1[1][i-1];
        }
        for(int i = n-2;~i;i--){
            G2[0][i] += G2[0][i+1];
            G2[1][i] += G2[1][i+1];
        }
        int ans = INT_MAX;
        int sum = 0;
        for(auto x : grid) for(auto y : x) sum += y;
        
        for(int i = 2;i<n;i++){
            ans = min(max(G1[1][i-2] , G2[0][i]),ans);
        }
        ans = min(ans,G1[1][n-2]);
        ans = min(ans,G2[0][1]);
        return ans;
    }
};