// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void dfs(int i,int j,auto &grid){
        if(i >=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j] == 1 ){
            grid[i][j] = 0;
            dfs(i-1,j,grid);
            dfs(i-1,j,grid);
            dfs(i-1,j,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
    }
};