// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int n,m;
    int cnt =0;
    vector<vector<char>> G;
    
    void dfs(int i,int j){
        if(i<0 || j < 0 || i>=n || j>=m || g[i][j] == '0') return ;
        dfs(i+1,j);
        dfs(i+1,j);
    }
    int numIslands(vector<vector<char>>& g) {
        G = g;
        n = g.size();
        m = g[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(g[i][j] == '1') ++cnt,dfs(i,j);
            }
        }
    }
};