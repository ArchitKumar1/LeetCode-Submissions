// https://leetcode.com/problems/count-fertile-pyramids-in-a-land

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int it = 2;
        int ans = 0;
        while(it--){
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> p(n,vector<int>(m,0));
            vector<vector<int>> s(n,vector<int>(m,0));
            vector<vector<int>> cnt(n,vector<int>(m,0));
            p = grid;
            s = grid;
            for(int i =0;i<n;i++){
                for(int j = 1;j < m;j++){
                    if(grid[i][j]) p[i][j] += p[i][j-1];
                }
            }
            for(int i =0;i<n;i++){
                for(int j = m-2;j >= 0;j--){
                    if(grid[i][j]) s[i][j] += s[i][j+1];
                }
            }
            for(int i = 0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] == 0) continue;
                    int left = p[i][j];
                    int right = s[i][j];
                    int top = (i?cnt[i-1][j] : 0);
                    int mini = min(left,right);
                    if(mini > top){
                        cnt[i][j] = top+1;
                    }else{
                        cnt[i][j] = mini;
                    }
                    if(cnt[i][j]){
                        ans += cnt[i][j]-1;
                    }
                }
            }
            for(int j=0;j<m;j++){
                for(int i =0;i<n/2;i++){
                    swap(grid[i][j],grid[n-i-1][j]);
                }
            }
        }
        cout << endl;
        return ans;
    }
};