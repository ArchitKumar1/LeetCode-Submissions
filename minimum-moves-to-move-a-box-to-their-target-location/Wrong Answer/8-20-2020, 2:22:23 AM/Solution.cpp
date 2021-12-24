// https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location

class Solution {
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
public:
    int n,m;
    
    bool valid(vector<vector<char>>& grid,int i,int j ){
        if(i < 0 || j < 0 || i >=n || j>=n) return false;
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
        if(dfs(grid,px,py,npx,npy,vis)) return true;
        return false;
    }
        
        
        
    
    int minPushBox(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int S=-1,B=-1,T=-1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 'S') S = i*n+j,grid[i][j] ='.';
                if(grid[i][j] == 'B') B = i*n+j,grid[i][j] ='.';
                if(grid[i][j] == 'T') T = i*n+j,grid[i][j] ='.';
            }
        }
        
        queue<pair<int,int>> qq;
        qq.push({S,B});
        int ans = 0;
        
        while(qq.size()){
            int l = qq.size();
            ans += 1;
            cout << "RISING SUN" << endl;
            for(int i = 0;i<l;i++){
                int p = qq.front().first;
                int b = qq.front().second;
                qq.pop();
                
                
                int px = p/n,py = p%n;
                int bx = b/n,by = b%n;
                
                
                cout << px << " " << py << " " << bx << " " << by << endl;
                if(b == T) return ans;
                
                for(int k = 0;k<4;k++){
                    int nbx = bx + dx[k];
                    int nby = by + dy[k];
                    
                    int npx = bx - dx[k];
                    int npy = by - dy[k];
                    
                    
                    if(valid(grid,nbx,nby) && valid(grid,npx,npy)){
                        grid[bx][by] = '#';
                        bool cw = canwalk(grid,px,py,npx,npy);
                        
                            // cout << cw << " " << px << " " << py << " " << npx << " " << npy << endl;
                        if(cw){
                            cout << "OK" << endl;
                            qq.push({b,nbx*n+nby});
                        }
                        grid[bx][by] = '.';
                    }
                }
            }
        }
        return -1;
    }
};