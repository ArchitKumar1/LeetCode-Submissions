// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int n,m;
    int cnt =0;
    vector<vector<char>> G;
    
    void dfs(int i,int j){
        if(i<0 || j < 0 || i>=n || j>=m || G[i][j] == '0') return ;
        G[i][j] = '0';
        dfs(i+1,j);
        dfs(i-1,j);dfs(i,j+1);dfs(i,j-1);
    }
    int numIslands(vector<vector<char>>& g) {
        if(g.size() == 0) return 0;
        G = g;
        n = g.size();
        m = g[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(G[i][j] == '1') {
                    ++cnt;
                    dfs(i,j);
                }
            }
        }
        return cnt;
    }
};