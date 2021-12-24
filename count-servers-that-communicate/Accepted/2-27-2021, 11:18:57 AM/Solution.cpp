// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> r(n),c(m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]) r[i]+=1,c[j]+=1;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]) ans +=((r[i]-1 > 0) || (c[j]-1 > 0));
            }
        }
        return ans;

    }
};