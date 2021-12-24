// https://leetcode.com/problems/shortest-path-to-get-all-keys

class Solution {
public:
    
    struct s{
        int i,j,k;
    };
    
    bool lo(char c){
        return c<='z' && c>='a';
    }
    bool hi(char c){
        return c<='Z' && c>='A';
    }
    int shortestPathAllKeys(vector<string>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        bool found = 0;
        
        queue<s> qq;
        s start;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '@'){
                    start.i = i,start.j = j,start.k = 0;
                }
            }
        }
        
        map<char,int>m1;
        int pos = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(lo(grid[i][j])){
                    m1[grid[i][j]] = pos;
                    char nc = ('A' + grid[i][j]-'a');
                    m1[nc] = pos;
                    pos++;
                }
            }
        }
        qq.push(start);
        
        int dx[4] ={1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        
        int K = 1 << 6;
        int vis[n][m][K];
        memset(vis,0,sizeof(vis));
        
        while(qq.size()){
            int sz = qq.size();
            
            for(int i = 0;i<sz;i++){
                s top = qq.front();qq.pop();
                
                if(top.i < 0 || top.j < 0 || top.i > n-1 || top.j > m-1) continue;
                
                if(vis[top.i][top.j][top.k] == 1) continue;
                vis[top.i][top.j][top.k] = 1;
                
                if(hi(grid[top.i][top.j])){
                    if((top.k & (1 << m1[grid[top.i][top.j]])) == 0){
                        continue;
                    }
                }
                if(lo(grid[top.i][top.j])){
                    top.k |=  (1 << m1[grid[top.i][top.j]]);
                }
                
                if(top.i == n-1 && top.j == m-1){
                    found = 1;
                    qq = queue<s>();
                    break;
                } 
                for(int k = 0;k<4;k++){
                    int ii = top.i + dx[k];
                    int jj = top.j + dy[k];
                    
                    s newtop;
                    newtop.i = ii,newtop.j = jj,newtop.k = top.k;
                    qq.push(newtop);
                    
                }
            }
            ans += 1;
        }
        return !found?-1:ans-1;
    }
};