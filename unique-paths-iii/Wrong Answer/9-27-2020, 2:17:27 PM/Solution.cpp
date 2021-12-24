// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:
    int n ,m;
    vector<vector<int>> G;
    bool safe(int i,int j){
        return  i>=0 && j>=0 && i<n && j<m;
    }
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int nos_mask = 0;
    
    int dfs(int i,int j,int mask){
        if(!safe(i,j)) return 0;
        if(G[i][j] == -1) return 0;
        int pos = m*i+j;
        if(mask & (1<<pos)) return 0;
        mask|=(1<<pos);
        
        if(G[i][j] == 2){
            if(nos_mask == mask){
                //cout << nos_mask << " 1 " << mask << endl;
                return 1;
            }else{
                //cout << nos_mask << " 0 " << mask << endl;
                return 0;
            }
        }
        
        int ans = 0;
        for(int k = 0;k<4;k++){
            ans += dfs(i+dx[k],j+dy[k],mask);
        }
        return ans;
    
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        G = grid;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(G[i][j] != -1 ){
                    nos_mask|=(1<<(m*i+j));
                }
            }
        }
        
        return dfs(0,0,0);
    }
};