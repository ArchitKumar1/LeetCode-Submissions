// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int d;
     void dfs(vector<vector<int>> &grid,int i,int j){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1){
            grid[i][j]=0;
            d++;
            dfs(grid,i-1,j);
            dfs(grid,i+1,j);
            dfs(grid,i,j-1);
            dfs(grid,i,j+1);
            //dfs(grid,i,j-1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=0;
        for(auto i=0;i<grid.size();i++){
            for(auto j=0;j<grid[0].size();j++){
                d=0;
                if(grid[i][j]==1) {
                    dfs(grid,i,j);
                    m=max(m,d);
                }
            }
        }
        return m;
    }
};