// https://leetcode.com/problems/shift-2d-grid

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k = k%(m*n);
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                int total = n*i + j;
                total += k;
                total %= m*n;
                int x = total/n;
                int y = total%n;
                cout <<i << " " << j << " " << x << " " << y << " " << total <<  endl;

                arr[x][y] = grid[i][j];
            }
        }
        return arr;
    }
};
