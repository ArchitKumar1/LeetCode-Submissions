// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int l=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(i==grid.size()-1  || grid[i+1][j]) l++;
                    if(i==0 || grid[i-1][j]) l++;
                    if(j==0 || grid[i][j-1]) l++;
                    if(j==grid[0].size() -1 || grid[i][j+1] ) l++;
                }
            }
        }
        return l;
    }
};