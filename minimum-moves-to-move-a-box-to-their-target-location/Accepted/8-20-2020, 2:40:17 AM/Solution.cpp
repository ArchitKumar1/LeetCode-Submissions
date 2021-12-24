// https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location

class Solution {
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    
public:
    int n,m;
    set<pair<int,int>> cnts;
    vector<vector<int>> dp;
    
    bool valid(vector<vector<char>>& grid,int i,int j ){
        if(i < 0 || j < 0 || i >=n || j>=m) return false;
        if(grid[i][j] == '#') return false;
        return true;
    }
    
    
    bool dfs(vector<vector<char>>&grid,int px,int py,int npx,int npy,vector<vector<int>> &vis){
        if(!valid(grid,px,py) || vis[px][py] == 1 ) return 0;
        vis[px][py] = 1;
        if(px == npx && py == npy) return 1;
        bool found = 0;
        for(int k = 0;k<4;k++){
            found |= dfs(grid,px+dx[k],py+dy[k],npx,npy,vis);
        }
        return found;
    }
    bool canwalk(vector<vector<char>>&grid,int px,int py,int npx,int npy){
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(dp[px*m+py][npx*m+npy]!=-1) return dp[px*m+py][npx*m+npy];
        if(dfs(grid,px,py,npx,npy,vis)) return dp[px*m+py][npx*m+npy] = true;
        return dp[px*m+py][npx*m+npy] = false;
    }
        
    int minPushBox(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int S=-1,B=-1,T=-1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 'S') {
                    S = i*m+j;
                    grid[i][j] ='.';
                    cout << i << " " << j << endl;
                }
                if(grid[i][j] == 'T') {
                    T = i*m+j;
                    grid[i][j] ='.';
                }
                if(grid[i][j] == 'B') {
                    B = i*m+j;
                    grid[i][j] ='.';
                }
            }
        }
        
        dp = vector<vector<int>>(m*n,vector<int>(m*n,-1));
        queue<pair<int,int>> qq;
        qq.push({S,B});
        int ans = 0;
        
        while(qq.size()){
            int l = qq.size();
            
            // cout << "RISING SUN" << endl;
            for(int i = 0;i<l;i++){
                int p = qq.front().first;
                int b = qq.front().second;
                qq.pop();
                
                
                int px = p/m,py = p%m;
                int bx = b/m,by = b%m;
                
                
                // cout << px << " " << py << " " << bx << " " << by << endl;
                if(b == T) return ans;
                
                for(int k = 0;k<4;k++){
                    int nbx = bx + dx[k];
                    int nby = by + dy[k];
                    
                    int npx = bx - dx[k];
                    int npy = by - dy[k];
                    
                    
                    if(valid(grid,nbx,nby) && valid(grid,npx,npy)){
                        grid[bx][by] = '#';
                            // cout << cw << " " << px << " " << py << " " << npx << " " << npy << endl;
                        if(canwalk(grid,px,py,npx,npy) && cnts.count({b,nbx*m+nby}) == 0){
                            qq.push({b,nbx*m+nby});
                            cnts.insert({b,nbx*m+nby});
                        }
                        grid[bx][by] = '.';
                    }
                }
            }
            ans += 1;
        }
        return -1;
    }
};