// https://leetcode.com/problems/max-increase-to-keep-city-skyline

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> r(n),c(n);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                r[i] = max(r[i],grid[i][j]);
                c[j] = max(c[j],grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                ans += min(c[i],r[j]) - grid[i][j];
            }
        }
        return ans;
        
    }
};