// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    
    
    int n,m;
    vector<vector<int>> M;
    
    int dfs(int i,int j){
        int ans =1 ;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int k = 0;k<4;k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(M[x][y] <= M[i][j]) continue;
            ans = max(ans,1 + dfs(x,y));
        }
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& ma) {
        M = ma, n = ma.size();
        if(n == 0) return 0;
        m = ma[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans = max(ans,dfs(i,j));
            }
        }
        return ans;
    }
};