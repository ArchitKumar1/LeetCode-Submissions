// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int n,m;
    int dfs1(vector<vector<int>>& grid,int i,int j){
        int ans = 0;
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0 ){
            return 1;
        }
        else if(grid[i][j] == 1){
            grid[i][j] =-1;
            int ans = dfs1(grid,i-1,j) + dfs1(grid,i+1,j) + dfs1(grid,i,j+1) + dfs1(grid,i,j - 1) ;
            return ans;
        }
        else return 0;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        //FASTIO
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        n = grid.size();
        m = grid[0].size();
        int peri = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    peri += dfs1(grid,i,j);
                }
            }
        }
        return peri;
    }
};